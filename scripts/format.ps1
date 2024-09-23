$clang_format = "C:\Program Files (x86)\Microsoft Visual Studio\2017\WDExpress\Common7\IDE\VC\VCPackages\clang-format.exe"

Get-ChildItem -Recurse *.cpp -Exclude .\build |
  ForEach-Object {
    Write-Output $_.FullName
    & $clang_format -i -style=file --fallback-style=LLVM $_.FullName
  }
