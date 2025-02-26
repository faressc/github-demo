# Little Github Demo

This is a little demo to show how to use Git/Github for shared projects.

## Step X: Allow Github Actions to write to the repository

To allow Github Actions to release artifacts to the repository, we need to allow Github Actions to write to the repository. For this, go to the repository settings and enable Actions/General/Workflow permissions/Read and write permissions.

## Step X: Add a new branch ruleset

Next we want to make sure that we can only merge into the main branch via a pull request, that passes the tests and is reviewed by at least one person. For this we need to add a new branch ruleset. To add a new branch ruleset, go to the 
Repository Settings/Rules/New ruleset/New branch ruleset:

- Ruleset Name: protect-main
- Enforcement status: Active
- Target branches:
    - Add target
    - Include by pattern: main
- Branch rules:
    - Restrict deletions: Enabled
    - Require a pull request before merging: Enabled
        - Required approvals: 1
    - Require status checks to pass:
        - Add checks
        - build_test / Linux-x86_64
        - build_test / Windows-x86_64
        - build_test / macOS-x86_64
        - build_test / macOS-x86_64
- Block force pushes: Enabled

Optinal: Create a similar ruleset for tags. Repository Settings/Rules/New ruleset/New tag ruleset:

- Ruleset Name: protect-tags
- Enforcement status: Active
- Target branches:
    - Add target
    - Include all tags
- Branch rules:
    - Restrict deletions: Enabled
    - Require status checks to pass:
        - Add checks
        - build_test / Linux-x86_64
        - build_test / Windows-x86_64
        - build_test / macOS-x86_64
        - build_test / macOS-x86_64
- Block force pushes: Enabled
