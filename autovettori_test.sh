#!/bin/bash

echo '    [ 2 1 0 ]                  [ 4 ]                  [ 1 -1  1 ]'
echo 'A = [ 1 3 1 ] ==> autovalori = [ 2 ]    autovettori = [ 2  0 -1 ]'
echo '    [ 0 1 2 ]                  [ 1 ]                  [ 1  1  1 ]'
printf 'a\n3\n2\n1\n0\n1\n3\n1\n0\n1\n2' | ./ViennaCLTest
