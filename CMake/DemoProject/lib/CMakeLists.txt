set(libSrcs core.cpp util.cpp)
add_library(utilLib SHARED ${libSrcs})

install(TARGETS utilLib DESTINATION lib)
