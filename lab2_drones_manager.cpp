#include "lab2_drones_manager.hpp"

// TODO: Implement all of the listed functions below

DronesManager::DronesManager() {
}

DronesManager::~DronesManager() {
}

bool operator==(const DronesManager::DroneRecord& lhs, const DronesManager::DroneRecord& rhs) {
	return false;
}

unsigned int DronesManager::get_size() const {
	return size;
}

bool DronesManager::empty() const {
	if (size == 0) return true;
	else return false;
}

DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
	if (DroneRecord[index]== NULL) return DroneRecord(size-1);
	else if(empty) return 0;
	else return DroneRecord(index);
}

unsigned int DronesManager::search(DroneRecord value) const {
	if(empty)return 0;
	else{
		for(int i = 0; i < size-1; i++){
			if (DroneRecord(i) == value) return i;
		}
		return size;
	}
}

void DronesManager::print() const {
	if (size == 0){
		cout<< "The list is empty" << endl;
	}
	else{
		DroneRecord* curr = first;
		while(curr != NULL){
			if (curr -> next != NULL){
				cout<< curr -> droneID <<;
			}
			else{
				cout<< current -> droneID << endl;
			}
			curr = curr -> next;
		}
	}
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
	int count = 0;
	if (index == 0) {
		insert_front(value);
		return true;
	}
	else{
		DroneRecord* curr = first;
		while (count <= index){
			if (count == DronesManager(index)){
				value -> next = curr-> next;
				curr -> next -> prev = value;
				curr -> next = value;
				value -> prev = curr;
			}
			curr = curr -> next;
			count++;
		}
		return true;
	}
	return false;
}

bool DronesManager::insert_front(DroneRecord value) {
	DroneRecord* curr = first;
	if(curr == NULL){
		curr = value;
		curr -> prev = NULL;
		curr-> next = NULL;
		return true;
	}
	else{
		curr -> prev = value;
		value -> prev = NULL;
		value -> next = curr;
		return true;
	}
	return false;
}

bool DronesManager::insert_back(DroneRecord value) {
	DroneRecord* curr = last;
	if(curr == NULL){
		curr = value;
		curr -> prev = NULL;
		curr-> next = NULL;
		return true;
	}
	else{
		curr -> next = value;
		value -> prev = curr;
		value -> next = NULL;
		return true;
	}
	return false;
}

bool DronesManager::remove(unsigned int index) {
	int count = 0;
	if (DronesManager(index) == NULL) {
		return false;
	}
	else{
		DroneRecord* curr = first;
		while (count <= index){
			if (count == DronesManager(index)){
				curr -> next -> prev =  curr -> prev;
				curr -> prev -> next  = curr -> next;
				curr = NULL;
			}
			curr = curr -> next;
			count++;
		}
		return true;
	}
	return false;
}

bool DronesManager::remove_front() {
	DroneRecord* curr = front;
	if (first = NULL) return false;
	else {
		curr -> next -> prev = NULL;
		curr = NULL;
		return true;
	}
	return false;
}

bool DronesManager::remove_back() {
	DroneRecord* curr = last;
	if (first = NULL) return false;
	else {
		curr -> prev -> next = NULL;
		curr = NULL;
		return true;
	}
	return false;
}

bool DronesManager::replace(unsigned int index, DroneRecord value) {
	int count = 0;
	if (DronesManager(index) == NULL) {
		return false;
	}
	else{
		DroneRecord* curr = first;
		while (count <= index){
			if (count == DronesManager(index)){
				curr -> next -> prev =  value;
				curr -> prev -> next = value;
				value -> next = curr -> next;
				value -> prev = curr -> prev
				curr = NULL;
			}
			curr = curr -> next;
			count++;
		}
		return true;
	}
	return false;
}

bool DronesManager::reverse_list() {
	DroneRecord* curr = last;
	if(curr == NULL) return false;
	else if (curr == first) return true;
	else{
		while (curr != NULL){
			cur -> next = cur -> prev;
			cur -> prev = cur -> next;
			cur = cur -> prev;
		}
		return true;
	}
	
	return false;
}

