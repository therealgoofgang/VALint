# Clean Build Instructions for VALint

## The C Linkage Error Fix is Complete

The `internal/Hookign/ret_spoofing.h` file has been fixed with proper `extern "C"` guards.

## Steps to Get a Fresh Working Copy

### 1. Backup Your Local Changes (if any)
If you have any uncommitted changes you want to keep, back them up first.

### 2. Delete Your Local Repository
Delete the entire `C:\Users\Jacob\Desktop\VALint\` folder.

### 3. Download Fresh from GitHub
Go to: https://github.com/therealgoofgang/VALint/tree/offset-update-aug-2026

Click the **Code** button → **Download ZIP**

Extract to `C:\Users\Jacob\Desktop\`

### 4. Open Project in Visual Studio
1. Open Visual Studio 2022
2. File → Open → Project/Solution
3. Navigate to `C:\Users\Jacob\Desktop\VALint\internal\internal.sln`
4. Click Open

### 5. Build
1. Make sure build configuration is: **Debug | x64**
2. Build → Rebuild Solution

## What Was Fixed

The file `internal/Hookign/ret_spoofing.h` now has proper `#ifdef __cplusplus` guards around the `extern "C"` block:

```cpp
#ifdef __cplusplus
extern "C" {
#endif

extern void spoofcall_stub();
extern uintptr_t proxy_call_returns[];
extern size_t proxy_call_returns_size;
extern size_t proxy_call_fakestack_size;
extern uintptr_t* proxy_call_fakestack;

#ifdef __cplusplus
}  // end extern "C"
#endif
```

This ensures that C++ STL headers (like `<algorithm>`, `<vector>`, etc.) are not compiled with C linkage, which was causing the 306+ template errors.

## If You Still Get Errors

If after a fresh download you still get errors, the issue might be with:
1. Visual Studio itself needing a restart
2. Windows Defender or antivirus interfering
3. Missing Windows SDK or Visual Studio components

In that case, try:
- Close Visual Studio completely
- Restart your computer
- Reopen Visual Studio and try again
