#ifndef _dc_ch_reference_
#define _dc_ch_reference_

#include "../defines.h"

class DcChReference
{
private:
    SmeJson json_data;
    char* json = nullptr;

public:
// Function: ~DcChReference

//     distructor of the class, frees up the memory occupied by the array/s

//     Prototype:
//         ~DcChReference()

//     Parameters:

//     Returns:
///@return         void
    ~DcChReference()
    {
        delete[] json;
        json = nullptr;
    }

// Function: DcChReference.set

//     A message referencing an existing Channel

//     Prototype:
//         void DcChReference::set(const char* channelId);

//     Parameters:
///@param         channelId - the id of the referenced channel
        
//     Returns:
///@return         void

    void set(const char* channelId);
    
// Function: DcChReference.get

//     return the json script

//     Prototype:
//         void DcChReference::get();

//     Parameters:

//     Returns:
///@return         char*
    char* get();
};

#endif