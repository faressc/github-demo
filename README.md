# Little Github Demo

This is a little demo to show how to use Git/Github for shared projects.

![on_tag](https://github.com/faressc/github-demo/actions/workflows/on_tag.yml/badge.svg)
![build_run](https://github.com/faressc/github-demo/actions/workflows/build_run.yml/badge.svg)
![build_test](https://github.com/faressc/github-demo/actions/workflows/build_test.yml/badge.svg)

## Build the repo locally

To build the repository locally, you need to have cmake installed. Then you can run the following commands:

```bash
cmake -B build
cmake --build build
```

> Note: This CMakeLists.txt requires the project to have a tag of sort `vX.Y.Z` where `X`, `Y`, and `Z` are integers. This is used to set the project version. If you don't have a tag, the cmake configuration will fail.

You can then exceute the binary in the build directory:

```bash
# Linux and macOS
./build/main
# Windows
.\build\<build_type>\main.exe
```

## Build options

The build can be configured with the following options:

- `WITH_TESTS`: Enable the tests (default: ON)
- `WITH_INSTALL`: Enable the install target (default: ON)

## Run the tests

```bash
cmake -B build -DWITH_TESTS=ON
cmake --build build
# Run the tests on Linux and macOS
./build/test
# Windows
.\build\<build_type>\test.exe
```

## Install the project

```bash
cmake -B build -DWITH_INSTALL=ON
cmake --build build
cmake --install build
```

By default the install directory `${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-${PROJECT_VERSION}` is used. This can be changed by setting the `CMAKE_INSTALL_PREFIX` variable.

## Add a release

To allow Github Actions to release artifacts to the repository, we need to allow Github Actions to write to the repository. For this, go to the repository settings and enable Settings -> Actions -> General -> Workflow permissions -> Read and write permissions.

We can now add a new release by creating a new tag. Github workflows will automatically create a release and upload the artifacts.

```bash
git tag -a v0.1.0 -m "Release 0.1.0"
git push --follow-tags
```

## Protect the main branch

We can add different rules to the repository to protect the main branch. This guide shows how to add a rule that requires a pull request to merge into the main branch, that passes the tests and is reviewed by at least one person.

Go to the repository settings and add a new ruleset:

Settings -> Rules -> Rulesets -> New ruleset -> New branch ruleset:

- Ruleset Name: protect-main
- Enforcement status: Active
- Target branches:
    - Add target
    - Include by pattern: main
- Branch rules:
    - Restrict deletions: Enabled
    - Require a pull request before merging: Enabled
        - Required approvals: 0 (for this demo)
    - Require status checks to pass:
        - Add checks
        - test_result
- Block force pushes: Enabled

Optional: Create a similar ruleset for tags.

Settings -> Rules -> Rulesets -> New ruleset -> New tag ruleset:

- Ruleset Name: protect-tags
- Enforcement status: Active
- Target branches:
    - Add target
    - Include all tags
- Branch rules:
    - Restrict deletions: Enabled
    - Require status checks to pass:
        - Add checks
        - test_result
- Block force pushes: Enabled

## Not covered in this demo

- Secrets
- Code signing on macOS
