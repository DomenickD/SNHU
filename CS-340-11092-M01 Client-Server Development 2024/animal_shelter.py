from pymongo import MongoClient

class AnimalShelter(object):
    """ CRUD operations for Animal collection in MongoDB """

    def __init__(self, username, password):
        # Connection Variables
        USER = username
        PASS = password
        HOST = 'nv-desktop-services.apporto.com'
        PORT = 30179
        DB = 'AAC'
        COL = 'animals'
	#
        # Initialize Connection
        #
        self.client = MongoClient(f'mongodb://{USER}:{PASS}@{HOST}:{PORT}/?authSource=admin')
        self.database = self.client[DB]
        self.collection = self.database[COL]

    def create(self, data):
        if data is not None:
            result = self.collection.insert_one(data)
            return True if result.acknowledged else False
        else:
            raise Exception("Nothing to save, because data parameter is empty")

    def read(self, query):
        if query is not None:
            result = list(self.collection.find(query))
            return result if result else []
        else:
            raise Exception("Query parameter is empty, try again!")
            
    def update(self, criteria, update_data):
        if criteria and update_data:
            update_result = self.database.animals.update_many(criteria, {'$set': update_data})
            return update_result.modified_count
        else:
            raise Exception("Update data must be provided to update records.")
    
    def delete(self, criteria):
        if criteria:
            delete_result = self.database.animals.delete_many(criteria)
            return delete_result.deleted_count
        else:
            raise Exception("Must specifiy what to delete in records.")

