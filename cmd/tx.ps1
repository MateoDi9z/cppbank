Clear-Host

$txdb = "..\db\TxDB.txt"
$exe = "..\a.exe"

if (-Not (Test-Path $txdb)) {
    New-Item -Path $txdb -ItemType File   
}

if (Test-Path $exe) {
    Remove-Item $exe
}

g++ .\main.cpp -fpermissive;
.\a.exe tx