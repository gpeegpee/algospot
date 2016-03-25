# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# http://doc.scrapy.org/en/latest/topics/items.html

import scrapy

class BookstoreItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
	book_title = scrapy.Field()
	book_category = scrapy.Field()
	book_author = scrapy.Field()
	book_image_url = scrapy.Field()
	book_description = scrapy.Field()
	book_release_date = scrapy.Field()
	book_isbn10 = scrapy.Field()
	book_isbn13 = scrapy.Field()
	book_publisher = scrapy.Field()
	pass
