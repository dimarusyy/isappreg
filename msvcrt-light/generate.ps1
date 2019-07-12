$file="msvcrt"
if (Test-Path "$file.def") 
{
  Remove-Item "$file.def"
}
if (Test-Path "$file.lib") 
{
  Remove-Item "$file.lib"
}

Add-Content "$file.def" "EXPORTS"
dumpbin /exports c:\windows\system32\msvcrt.dll | %{ $a=$_.split(' ', [System.StringSplitOptions]::RemoveEmptyEntries); if ($a.length -eq 4 -and $a[1] -match "^[0-9A-F]+$" -and $a[0] -match "^[0-9A-F]+$"){ Add-Content "$file.def" $a[3];} }
lib /OUT:"$file.lib" /DEF:"$file.def" /machine:x64