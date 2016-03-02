
/** @file epirtConverter.h */
#ifndef NIH_EPIRT_CONVERTER_H
#define NIH_EPIRT_CONVERTER_H

#include "ismrmrd/ismrmrd.h"

#include "GenericConverter.h"

class NIHepirtConverter: public PfileToIsmrmrd::GenericConverter
{
public:
   NIHepirtConverter() : PfileToIsmrmrd::GenericConverter() {}
};

#endif /* NIH_EPIRT_CONVERTER_H */

