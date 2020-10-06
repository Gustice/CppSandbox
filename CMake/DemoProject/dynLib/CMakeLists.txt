set(dynLibSrcs dynLib.cpp util.cpp)
add_library(dynamicLibrary SHARED ${dynLibSrcs})

install(TARGETS dynamicLibrary DESTINATION dynLib)
