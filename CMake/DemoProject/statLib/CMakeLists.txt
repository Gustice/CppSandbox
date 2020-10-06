set(statLibSrcs statLib.cpp)
add_library(staticLibrary STATIC ${statLibSrcs})

install(TARGETS staticLibrary DESTINATION statLib)
