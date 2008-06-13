

#ifndef ValueCompare_H 

#define ValueCompare_H 

//#include <utility>

//----------------------------------------------------------------------------
// ValueCompare.h                                                                  
//----------------------------------------------------------------------------

//## package Design::oxf::Services::Containers::STLContainersSupport 


// STL compare functor.
// Used for qualified relations that are implemented with STL containers.
//## class ValueCompare 
template <class Key, class Value> class ValueCompare  {


////    Constructors and destructors    ////
public :
    
    // constructor
    // Argument Value value : 
    // The value to find
    //## operation ValueCompare(Value) 
    ValueCompare(Value value) : value_(value) {
        //#[ operation ValueCompare(Value) 
        //#]
    }
    
    
    //## auto_generated 
    ~ValueCompare();


////    Operations    ////
public :
    
    // the operator used by std::find_if() to compare the map element with the one we are searching for
    // Argument const std::pair<Key,Value>& item : 
    // The map item to check against the value
    //## operation operator()(const std::pair<Key,Value>&) 
    inline bool operator()(const std::pair<Key,Value>& item) {
        //#[ operation operator()(const std::pair<Key,Value>&) 
        return (item.second == value_);
        //#]
    }
    


////    Attributes    ////
private :
    
    // The value to compare against (this is what we are looking for)
    Value value_;		//## attribute value_ 
    

};
//## class ValueCompare 



template <class Key, class Value> ValueCompare<Key, Value> ::~ValueCompare() {
}



#endif  
//
//! Log: $Log: ValueCompare.h $
//! Log: Revision 1.15  2007/04/06 07:07:56  ilgiga
//! Log: bug fix 98191
//


