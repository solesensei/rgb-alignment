/*unsharp filter*/
#include <assert.h>
#include <string>

#include "../include/mvc.h"
#include "../include/filters.hpp"

#include "../include/plugin.hpp"

using std::string;
using std::cerr;
using std::endl;
using std::tuple;

extern "C" Plugin* create_object()
{
  return new Plugin;
}

extern "C" void destroy_object( Plugin* object )
{
  delete object;
}

Plugin::Plugin(): name("unsharp") {}

Image custom(Image src_image, Matrix<double> kernel) {
    return src_image.unary_map(unaryOp(kernel));  
}

Image Plugin::processing(Image src_image, const int radius) {
    cerr << "unsharping" << endl;
    
    Matrix<double> kernel = {{-1.0/6.0, -2.0/3.0, -1.0/6.0},
                             {-2.0/3.0, 13.0/3.0, -2.0/3.0},
                             {-1.0/6.0, -2.0/3.0, -1.0/6.0}};
    Image tmp = custom(src_image,kernel);
    return tmp;
}