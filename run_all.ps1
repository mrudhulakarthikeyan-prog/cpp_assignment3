$ErrorActionPreference = "Continue"
$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$logDir = Join-Path $root "Evidence\RunLogs"
New-Item -ItemType Directory -Force -Path $logDir | Out-Null
$log = Join-Path $logDir "run_all_output.txt"
"DSA01 Assignment 3 - execution log" | Set-Content $log
"Compiler:" | Add-Content $log
g++ --version 2>&1 | Tee-Object -FilePath $log -Append

$tasks = @(
  @{Dir="Q1"; File="main.cpp"; Exe="q1.exe"},
  @{Dir="Q2"; File="main.cpp"; Exe="q2.exe"},
  @{Dir="Q2"; File="complete_the_code.cpp"; Exe="q2_complete.exe"},
  @{Dir="Q3"; File="main.cpp"; Exe="q3.exe"},
  @{Dir="Q3"; File="predict_output.cpp"; Exe="q3_predict.exe"},
  @{Dir="Q4"; File="main.cpp"; Exe="q4.exe"},
  @{Dir="Q4"; File="complete_the_code.cpp"; Exe="q4_complete.exe"},
  @{Dir="Q5"; File="main.cpp"; Exe="q5.exe"},
  @{Dir="Q5"; File="predict_output.cpp"; Exe="q5_predict.exe"},
  @{Dir="Q6"; File="main.cpp"; Exe="q6.exe"},
  @{Dir="Q7"; File="main.cpp"; Exe="q7.exe"}
)
foreach ($task in $tasks) {
  $dir = Join-Path $root $task.Dir
  $src = Join-Path $dir $task.File
  $exe = Join-Path $dir $task.Exe
  "`n===== $($task.Dir)\$($task.File) =====" | Tee-Object -FilePath $log -Append
  Push-Location $dir
  g++ -std=c++17 -Wall -Wextra $task.File -o $task.Exe 2>&1 | Tee-Object -FilePath $log -Append
  if ($LASTEXITCODE -eq 0) {
    & $exe 2>&1 | Tee-Object -FilePath $log -Append
  } else {
    "Compilation failed for $($task.Dir)\$($task.File)" | Tee-Object -FilePath $log -Append
  }
  Pop-Location
}
"`n===== Q1 experiments (expected compiler diagnostics) =====" | Tee-Object -FilePath $log -Append
Push-Location (Join-Path $root "Q1")
g++ -std=c++17 -Wall -Wextra -Wreorder reorder_warning.cpp -o reorder_warning.exe 2>&1 | Tee-Object -FilePath $log -Append
g++ -std=c++17 -Wall -Wextra no_default_array_error.cpp -o no_default_array_error.exe 2>&1 | Tee-Object -FilePath $log -Append
g++ -std=c++17 -Wall -Wextra explicit_test.cpp -o explicit_test.exe 2>&1 | Tee-Object -FilePath $log -Append
if ($LASTEXITCODE -eq 0) { .\explicit_test.exe 2>&1 | Tee-Object -FilePath $log -Append }
Pop-Location
"`nRun completed. See Evidence\RunLogs\run_all_output.txt" | Tee-Object -FilePath $log -Append
Write-Host "Finished. Log saved to Evidence\RunLogs\run_all_output.txt"
