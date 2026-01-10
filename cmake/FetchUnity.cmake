include(FetchContent)

# Keep Unity pinned for reproducibility.
FetchContent_Declare(unity GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git GIT_TAG v2.5.2)

# Fetch Unity sources
FetchContent_MakeAvailable(unity)
