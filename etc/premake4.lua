--
-- Copyright (C) 2013 Sergio Rodrigo
-- 
-- This software may be modified and distributed under the terms
-- of the MIT license. See the LICENSE file for details.
--

-- projects
lge = "lge"
test = "test"

-- main dirs
base_dir = ".."

-- src dirs
src_dir = base_dir .. "/src/"
lge_src_dir = src_dir .. "/lge/"
test_src_dir = src_dir .. "/test/"

-- generated dirs
lib_dir = base_dir .. "/lib/"
build_dir = base_dir .. "/build/"
bin_dir = base_dir .. "/bin/"

-- libs
liblge = "liblge.so"
all_sfml_libs = { "sfml-audio", "sfml-network", "sfml-graphics", "sfml-window", "sfml-system" }
libunittest = "UnitTest++"

solution ("lgeall")
	location (build_dir)
    includedirs { src_dir }

	configurations { "Debug", "Release" }
   
	configuration { "Debug" }
	    targetdir (bin_dir .. "Debug")
 
 	configuration { "Release" }
		targetdir (bin_dir .. "Release")
 
	if _ACTION == "clean" then
		os.rmdir(lib_dir .. liblge)
		os.rmdir(build_dir)
		os.rmdir(bin_dir)
	end

	project (lge)
		kind "SharedLib"
		language "C++"
		files { lge_src_dir .. "**.h", lge_src_dir .. "**.cpp" }
		targetdir (lib_dir)

		for _,sfmllib in pairs(all_sfml_libs) do libdirs { os.findlib(sfmllib) } end
		links(all_sfml_libs)

	project (test)
		kind "ConsoleApp"
		language "C++"
		files { test_src_dir .. "**.h", test_src_dir .. "**.cpp" }
		
		libdirs { os.findlib(libunittest) }
		links {lge}
		links {libunittest}

		for _,sfmllib in pairs(all_sfml_libs) do libdirs { os.findlib(sfmllib) } end
		links(all_sfml_libs)

