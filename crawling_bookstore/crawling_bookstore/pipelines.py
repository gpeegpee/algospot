# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: http://doc.scrapy.org/en/latest/topics/item-pipeline.html

import logging
import sys, os
import json

class BookstorePipeline(object):

	def __init__(self):
		self.file = open('book_list.json', 'w')

	def process_item(self, item, spider):
		newItem = {}
		newItem['book_title'] = item['book_title'].encode('utf-8')
		newItem['book_category'] = item['book_category'].encode('utf-8')
		newItem['book_author'] = item['book_author'].encode('utf-8')
		newItem['book_image_url'] = item['book_image_url'].encode('utf-8')
		newItem['book_description'] = item['book_description'].encode('utf-8')
		newItem['book_release_date'] = item['book_release_date'].encode('utf-8')
		newItem['book_isbn10'] = item['book_isbn10'].encode('utf-8')
		newItem['book_isbn13'] = item['book_isbn13'].encode('utf-8')
		newItem['book_publisher'] = item['book_publisher'].encode('utf-8')

		json.dumps(newItem, self.file, ensure_ascii=False)
		#self.file.write(jsonData)

		return item
