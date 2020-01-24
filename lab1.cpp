#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//implement the corresponding class Artwork that includes
//the required data attributes, empty constructor,
//parametric constructor, and overloaded operator ==.
//for the empty constructor, store 0 as default year.

// PURPOSE: Represents an instance of Artwork or one piece of Artwork

class Artwork{
	string artist_name, title;
	unsigned int year_made;// primitive data, so need to initialize
	public:
		//empty default constructor
		Artwork() : year_made(0) {}
		
		//parametric constructor using implicit setters
		Artwork(string new_artist, string new_title, unsigned int new_year) :
			artist_name(new_artist), title(new_title), year_made(new_year) {}
			
		// overloaded operator ==
		bool operator == (const Artwork& rhs) const{
			bool are_equal = artist_name == rhs.artist_name;
			are_equal = are_equal && title == rhs.title;
			are_equal = are_equal && year_made == rhs.year_made;
			return are_equal;
		}
};

//once a piece pf Artwork has been sold, it is recorded as an instance of SoldArtwork,
//which is a derived(child) class of Artwork
//for each sold piece, we need to store the customer na,e, customer address, and
//sale amount; the sale amount is stored as a double value 
class SoldArtwork : public Artwork {
	string cust_name, cust_addy;
	double sale_amount;
public :
	//empt/default constuctor
	SoldArtwork() : sale_amount(0) {} //implicitly calling Artwork
	
	//parametric constructor
	SoldArtwork(string new_cust_name, string new_cust_addy, double new_sale_amount,
		Artowrk new_artwork) : cust_name(new_cust_name), cust_addy(new_cust_addy), 
		sale_amount(new_sale_amount), Artowrk(new_artwork) // calling Artwork constructor
		{}
		//overload operator
	bool operator==(const SoldArtwork& rhs) {
		bool are_equal = cust_name == rhs.cust_name;
		are_equal = are_equal && cust_addy == rhs.cust_addy;
		are_equal = are equal && sale_amount == rhs.sale_amount;
		are_equal = are_equal && static_cast<Artwork>(rhs) == static_cast<Artwork>(*this);
		return are_equal; 
	}
};
//ArtCollection is used to store Artwork and SoldArtwork instances. implement the matching class
//ArtCollection, so that it includes a vector of Artwork instances and another vector of SoldArtwork
//instances. Do not implement explicit constructors
//for example, to deckare a vector of Artwork instances, write vector,<Artwork> my_artwork;

//PURPOSE : Represents models artwork pieces held by an art gallery
class ArtCollection {
	vector<Artwork> my_artwork; // private attribute; a collection of Artwork instances
	vector<SoldArtwork> my_sold_artwork; // private attribute; a collection of SoldArtwork instances
public:
	bool insert_artwork(const Artwork& artwork_info){ //method signature; specifies name and parametry only
	// use a bool to keep track of duplicate detection
		bool has_duplicate = false;
		//iterate through my_artwork to check for duplicate values
		for (int i = 0; i < my_artwork.size() && has_duplicate; ++i){
			//use operator== to compare vector element against the element that was passed in
			if (my_artwork[i] == artwork_info)
				has_duplicate = true;
		}
		
		//insert the given artwork into the Artwork vector
		if (has_duplicate == false){
			my_artwork.push_back(artwork_info);
		}
	
	// return true if insertion worked; else return false
	return !has_duplicate;
	}
	
	//PURPOSE: Faciliates a sale of Artwork and placemnt of SoldArtwork instance into the corresponding vector
	bool sell_artwork(const SoldArtwork& artwork_info){
			//iterate through my_artwork to find the Artwork that matches artwork_info
			for (int i = 0; i < my_artwork.size(); i++){
				if (my_artwork[i]; == static_cast<Artwork>(artwork_info)){
				swap(my_artwork[i], my_artwork[my_artwork.size()-1]);
				my_artwork.pop_back();
				my_sold_artwork.push_back(artwork_info);
				have_sold = true;
			}
		}
		return have_sold;
	}

	bool operator==(const ArtCollection& rhs) const {
		//iterate through my_artwork vectors of lhs and rhs
		//compare each pair of values and check if they are equal
		bool are_equal = true;
		
		if(my_artworksize() != rhs.my_artwork.size() || 
		   my_sold_artwork.size() != rhs.my_sold_artwork.size())
		   are_equal = false;
		   
		for(unsigned int i = 0; i < my_artwork.size() && are_equal; i++){
			if(!my_artwork[i] == rhs.my_artwork[i])
			are_equal = false;
		}
		
		for(unsigned int i = 0; i < my_sold_artwork.size() && are_equal; i++){
			if(!my_sold_artwork[i] == rhs.my_sold_artwork[i])
			are_equal = false;
		}
		return are_equal
	}
	
	//external function which will have direct access to private members of ArtCollection
	friend ArtCollection operator+(const ArtCollection& lhs, const ArtCollection& rhs);
		

};

ArtCollection operator+(const ArtCollection& lhs, const ArtCollection& rhs){
	ArtCollection target(lhs);
	
	for (unsigned int i = 0; i < rhs.my_artwork.size())
}

class ArtCollectionTest{
	void test_insert_artwork(){
		Artwork a1 ("Igor", "Da Igor", 2020);
		ArtCollection test_collection;
		
		cout<<(test_collection.insert_artwork(a1)) ?
			"Test insert_artwork passed" : "Test insert_artwork failed" << endl;
		assert(test_collection.my_artwork.size() == 1);
		cout<< "Test1 my_artwork.size() passed"<< endl;
		assert(test_collection.insert_artwork.size() == 1);
		cout<< "Test my_artwork.size() passed"<< endl;
		assert(test_collection.my_artwork.size() == 1);
		cout<< "Test my_artwork.size() passed"<< endl;
	}
};
//
int main() {
	Artwork a1, a2;
	SoldArtwork sa1, sa2;
	a1 = sa1;
	ArtCollection ac1, ac2;
	
	return 0;
}
