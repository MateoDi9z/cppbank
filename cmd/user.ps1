Clear-Host

$userdb = ".\db\UserDB.txt"
$exe = ".\a.exe"

if (-Not (Test-Path $userdb)) {
    New-Item -Path $userdb -ItemType File   
}

if (Test-Path $exe) {
    Remove-Item $exe
}

g++ .\main.cpp -fpermissive;
.\a.exe user