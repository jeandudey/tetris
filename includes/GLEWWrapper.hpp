#pragma once

#include <GL/glew.h>
#include <SDL_opengl.h>
#include <string>

#include <boost/exception/all.hpp>
#include <boost/core/noncopyable.hpp>

struct glew_error : virtual boost::exception, virtual std::exception { };
typedef boost::error_info<struct glew_error_info, GLenum> glew_errorenum;
typedef boost::error_info<struct glew_error_info, std::string> glew_errorstring;

class GLEW : private boost::noncopyable {
 public:
  GLEW() : initialized_(false)
  {
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::string str(reinterpret_cast<const char*>(
                        glewGetErrorString(err)));

        BOOST_THROW_EXCEPTION(glew_error() <<
                              glew_errorenum(err) <<
                              glew_errorstring(str));
    }
  }

  bool initialized() const { return initialized_; };

 private:
  bool initialized_;
};
