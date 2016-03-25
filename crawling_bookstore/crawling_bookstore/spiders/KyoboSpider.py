#!/usr/bin/python
# -*- coding: utf-8 -*-

import logging

from scrapy.spiders import Spider
from scrapy.contrib.spiders.init import InitSpider
from scrapy.selector import Selector
from scrapy.http import HtmlResponse
from scrapy.http import Request, FormRequest
from scrapy.linkextractors import LinkExtractor
from scrapy.contrib.spiders import Rule
from crawling_bookstore.items import BookstoreItem

from gevent import monkey
from gevent.pool import Pool
monkey.patch_all()

"""
from gevent import monkey; monkey.patch_all()
from gevent.pool import Pool
    def latest_talks(page=1):
        list_url = 'http://www.ted.com/talks/browse?page={0}'.format(page)
        talk_links = talk_links_from_listpage(list_url)
        # talks = [talk_from_page(url) for url in talk_links]
        pool = Pool(20)
        # XXX: constant talks = pool.map(talk_from_page, talk_links)
        return talks pprint(latest_talks()) # 단 5줄 변경만으로: 34초 8초
"""

"""
import gevent
from gevent import Greenlet
from gevent import monkey
from selenium import webdriver
monkey.patch_socket()

class WebCrawler:
    def __init__(self,urls=[],num_worker = 1):
        self.url_queue = Queue()
        self.num_worker = num_worker
    def worker(self,pid):
        driver = self.initializeAnImegaDisabledDriver()  #initilize the webdirver
        #TODO catch the exception
        while not self.url_queue.empty():
        url = self.url_queue.get()
        self.driver.get(url)
        elem = self.driver.find_elements_by_xpath("//script | //iframe | //img") # get such element from webpage
    def run(self):
        jobs = [gevent.spawn(self.worker,i) for i in xrange(self.num_worker)]
"""

# http://www.kyobobook.co.kr/search/sub/SearchEngbookCondition.jsp?Kc=SEHHETdetailsearch&orderClick=LJQ

class KyoboSpider(Spider):
    name = 'KyoboSpider'
    # http://www.kyobobook.co.kr/product/detailViewEng.laf?mallGb=ENG&ejkGb=ENG&linkClass=132701&barcode=9780123695284
    # 132701 : 외국도서 > 과학/기술 > 컴퓨터 > 컴퓨터일반

    # http://www.kyobobook.co.kr/category/categoryEng.laf?linkClass=1327&mallGb=ENG&orderClick=JBK
    allowed_domains = ["kyobobook.co.kr"]
    # 크롤링할 url
    start_urls = [
        "http://www.kyobobook.co.kr/product/detailViewEng.laf?mallGb=ENG&ejkGb=ENG&linkClass=132701&barcode=9780123695284",
        "http://www.kyobobook.co.kr/product/detailViewEng.laf?mallGb=ENG&ejkGb=ENG&linkClass=132307&barcode=9780123742544"
    ]

    amazon_start_url = [ "http://www.amazon.com/books-used-books-textbooks/b/ref=nav_shopall_bo?ie=UTF8&node=283155" ]

    # categoryRefinementsSection
    # http://www.amazon.com/s/ref=lp_5_pg_2?rh=n:283155,n:!1000,n:5&page=2&ie=UTF8&qid=1457174792
    # http://www.amazon.com/s/ref=sr_pg_3?rh=n:283155,n:!1000,n:5&page=3&ie=UTF8&qid=1457180079


    # /search/SearchEngbookMain.jsp?vPstrCategory=ENG&vPoutSearch=1&vPejkGB=ENG&vPpubNM=Morgan Kaufman&vPsKeywordInfo=Morgan Kaufman

    login_page = "http://www.daum.net/?t_nil_top=login"

    # Rule 객체를 이용해 크롤링 되는 사이트의 동작을 정의 한다.
    rules = (
        # Rule(SgmlLinkExtractor(allow=r'-\w+.html$'), callback='parse_item',
        # follow=True),
        Rule(LinkExtractor(allow=("\www\.daum\.net[^\s]*\/*$")), callback='parse', follow=True),
    )

    # initRequest 메소드가 맨 처음 시작 됨.
    def init_request(self):
        return Request(url=self.login_page, callback=self.login)

    # FormRequest를 이용해서 해당 페이지에서 submit요청을 보낸다.
    def login(self, response):
        return FormRequest.from_response(response, formdata={'id': 'userid', 'password': 'test'}, callback=self.check_login_response)

    def check_login_response(self, response):
        # check login success
        if 'info_my' in response.body:
            return self.initialized()
        else:
            return self.error()

    def initialized(self):
        return Request(url=self.start_urls, callback=self.parse)

    def parse(self, response):
        hxs = Selector(response)

        title = hxs.xpath('//div[@class="box_detail_point"]').xpath('h1[@class="title"]/strong/text()').extract_first()
        author = hxs.xpath('//div[@class="box_detail_point"]/div[@class="author"]/span/text()').extract_first()
        image_url = hxs.xpath('//div[@class="box_detail_cover"]/div[@class="cover"]').xpath('.//img/@src').extract_first()
        isbn13 = hxs.xpath('//span[@title="ISBN-13"]/text()').extract_first()
        isbn10 = hxs.xpath('//span[@title="ISBN-10"]/text()').extract_first()
        category = hxs.xpath('//ul[@class="list_detail_category"]/li/a[contains(@href, "category")]/text()').extract_first()
        release_date = hxs.xpath('//div[@class="box_detail_point"]/div[@class="author"]/span[@class="date"]/text()').extract_first()
        publisher = hxs.xpath('//div[@class="box_detail_point"]/div[@class="author"]/span[@class="name"]/a/text()').extract_first()
        description = hxs.xpath('//div[@class="box_detail_article"]/text()').extract_first()

        #self.logger.debug('title %s', title.strip())
        #self.logger.debug('author %s', author.strip())
        #self.logger.debug('image_url %s', image_url)
        #self.logger.debug('isbn13 %s', isbn13)
        #self.logger.debug('isbn10 %s', isbn10)
        #self.logger.debug('category %s', category.strip())
        #self.logger.debug('release_date %s', release_date.strip())
        #self.logger.debug('publisher %s', publisher)
        #self.logger.debug('description %s', description.strip())

        items = []
        count = 0

        # for detail in books:
        item = BookstoreItem()
        item['book_title'] = title.strip()
        item['book_category'] = category.strip()
        item['book_author'] = author.strip()
        item['book_image_url'] = image_url
        item['book_description'] = description.strip()
        item['book_release_date'] = release_date.strip()
        item['book_isbn13'] = isbn10
        item['book_isbn10'] = isbn13
        item['book_publisher'] = publisher
        count += 1
        items.append(item)

        return items
