macro( _set_if_not_empty var value )
  if( NOT "${value}" STREQUAL "" )
    set( ${var} "${value}" )
  endif()
endmacro()

set( _GIT_VERSION_MAJOR "2" )
set( _GIT_VERSION_MINOR "3" )
_set_if_not_empty( _GIT_VERSION_PATCH "0" )
_set_if_not_empty( _GIT_VERSION_TWEAK "" )
_set_if_not_empty( _GIT_VERSION_RC "" )
_set_if_not_empty( _GIT_VERSION_POST "" )
_set_if_not_empty( _GIT_VERSION_DEV "" )
_set_if_not_empty( _GIT_VERSION_HASH "277b7" )
