import os
from pymongo import MongoClient
from bson.objectid import ObjectId
from bson.json_util import dumps
import pprint

class AnimalShelter(object):
        """ CRUD operations for Animal collection in MongoDB """
        
        def __init__(self, username, password):
            # Initializing the MongoClient. This helps to
            # access the MongoDB databases and collections.
            self.client = MongoClient('mongodb://localhost:55728')
            self.database = self.client['AAC']
            
            
        #Create method to implement the C in CRUD
        def create(self, data):
            # Checks to see if the data is null or empty and returns false in either case
            if data is not None:
                data_create = self.database.animals.insert(data)
                #Creates data
                return data_create
            else:
                return False
            
            
        #Create method to implement the R in CRUD
        def read(self,data):
            # Checks to see if the data is null or empty and returns exception in either case
            if data is not None:
                data_read = self.database.animals.find_one(data,)
                #Reads data already in system
                return data_read
            else:
                exception = "Nothing to search, because search parameter is empty"
                return exception
        def readAll(self,data):
            data_read = self.database.animals.find(data,{"_id":False})
            return data_read
            
        #Create method to implement U in CRUD
        #Prompts user if Update option is selected
        def update(self, query, data):
            if data is not None:
                data_update = self.database.animals.update_one(query, data)
                #Updates data in system
                return data_update
            else:
                raise Exception("Nothing to update! Data parameter is empty/formatted incorrectly")

        #Create method to implement the D in CRUD
        #Prompts user if delete option is selected
        def delete(self,data):
            if data is not None:
                data_delete = self.database.animals.delete_one(data)
                #Deleted data in system
                return data_delete
            else:
                raise Exception("Nothing to delete! Parameter is empty/formart")