workspace "Fangh"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Fangh"
    location "Fangh"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FH_PLATFORM_WINDOWS",
            "FH_BUILD_DLL",
            "_WINDLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "FH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FH_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Fangh/vendor/spdlog/include",
        "Fangh/src"
    }

    links
    {
        "Fangh"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FH_PLATFORM_WINDOWS",
            "_MBCS"
        }

    filter "configurations:Debug"
        defines "FH_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "FH_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "FH_DIST"
        optimize "On"