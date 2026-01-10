# OBS Achievements Tracker

## MVP

### Configuration

1. Authenticates Xbox Live: gets an XSTS
2. Select Font, Color and Size

### Operation
1. Poll / Loop to get the current game being played
2. Poll / Get to get the achievements
3. Display the number of achievements unlocked

- Switch between Gamer points / Achievements? 
- Share feature (will require a server)?

## Setup

### Prerequisites
- OBS Studio
- Xbox Live account
- Xbox Live API access

### Steps to Build * Run on macOS

1. Clone the repository
2. On macOS, run `cmake --preset macos-dev`
3. Run `cd build_macos_dev`
4. Run `xcodebuild -configuration RelWithDebInfo -scheme achievements-tracker -parallelizeTargets -destination "generic/platform=macOS,name=Any Mac"`
5. Copy the binaries to your OBS Studio plugins folder
6. Start OBS Studio (`open frontend/RelWithDebInfo/OBS.app`)

```bash
cmake --preset macos-dev
cd build_macos_dev
xcodebuild -configuration RelWithDebInfo -scheme achievements-tracker -parallelizeTargets -destination "generic/platform=macOS,name=Any Mac"
```

### Run the tests

For local development on macOS, use the helper script that handles code signing from the root folder:

```bash
cmake --preset macos-dev
cmake --build build_macos_dev --target test_encoder --config RelWithDebInfo
ctest --test-dir build_macos_dev -C RelWithDebInfo --output-on-failure
```
or

```bash
ctest -C RelWithDebInfo --output-on-failure
```

For CI builds (which use universal OpenSSL), use ctest directly:

```bash
cmake --preset macos-ci -DBUILD_TESTING=ON
cmake --build build_macos --target test_encoder --config RelWithDebInfo
ctest --test-dir build_macos -C RelWithDebInfo --output-on-failure
```


{"Properties":{"AuthMethod":"ProofOfPossession","Id":"{90eaeebb-5212-30fb-baae-9e74a36012aa}","DeviceType":"iOS","SerialNumber":"{90eaeebb-5212-30fb-baae-9e74a36012aa}","Version":"0.0.0","ProofKey":{"kty":"EC","crv":"P-256","x":"9I_BhcP50opRVRBHYRvozXes554VVrKB7RlTgtlm9hU","y":"9LRgfqXSFQsZZ05qDopk5pf-d9TXF8bexNv6HNzPJmE","alg":"ES256","use":"sig"}},"RelyingParty":"http://auth.xboxlive.com","TokenType":"JWT"}
{"Properties":{"AuthMethod":"ProofOfPossession","Id":"{90eaeebb-5212-30fb-baae-9e74a36012aa}","DeviceType":"iOS","SerialNumber":"{90eaeebb-5212-30fb-baae-9e74a36012aa}","Version":"0.0.0","ProofKey":{"kty":"EC","crv":"P-256","x":"KmCnOlAo5S9Hpd5Jw96ajFHzK2WfXY0P3qIYbbf8oio","y":"SjjdWhgrSDp7--p7d-Q_qt4Ae3ZLLidXKhqyheOZhyI","alg":"ES256","use":"sig"}},"RelyingParty":"http://auth.xboxlive.com","TokenType":"JWT"}

AAAAAQHcgkRLetOAOBgHIoN0hmw9QdzJXO4RWPiJ1u4x7T2ypliU9cFFr4xG0EVpfYAEeJzE0l1Mwr3iULywaheCtukjIdsGd8z/xw==
AAAAAQHcgRN+cXoAwH+14u6l/pu/7UlmRJtHUZ/xPZ4+yH972ipcgFVpSzZ9zb1htOnZM1nOw9Vn3qc1ZPXGqwYBufbpCw3emMfNUg==