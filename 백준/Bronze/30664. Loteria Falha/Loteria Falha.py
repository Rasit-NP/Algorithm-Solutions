import sys

while(1):
    n = int(sys.stdin.readline())
    if n == 0:
        break
    if n%42:
        sys.stdout.write("TENTE NOVAMENTE\n")
    else:
        sys.stdout.write("PREMIADO\n")