#!/usr/bin/env php
<?php
function run($operation, $expected, $digits="0123456789") {
    $descriptorspec = array(
       0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
       1 => array("pipe", "w")  // stdout is a pipe that the child will write to
    );

    //valgrind -q --error-exitcode=9 --tool=memcheck --leak-check=full
    $process = proc_open("./Calculator $digits", $descriptorspec, $pipes);

    if(is_resource($process)) {
        fwrite($pipes[0], $operation);
        fclose($pipes[0]);

        $result = fread($pipes[1], 500);
        $result = substr($result, 0, strlen($result)-1);
        fclose($pipes[1]);
        $return_value = proc_close($process);
        if($return_value != 0) return 0;
        return $result == $expected;
    }
}

function tests($array) {
    $errors = 0;
    foreach ($array as $test) {
        $message = str_pad($test["label"], 50);
        if(!array_key_exists("digits", $test)) $test["digits"] = "0123456789";
        if(run($test["operation"], $test["expected"], $test["digits"]))
            echo $message . ": \033[01;32mSUCCESS\033[0m\n";
        else {
            echo $message . ": \033[01;31mFAILURE\033[0m\n";
            $errors ++;
        }
    }
    return $errors;
}
$a = random_int(1000000000000000, 9999999999999999);
$b = random_int(1000000000000000, 9999999999999999);
$aplusb = $a + $b;
$c = strval(random_int(1000000000000000, 9999999999999999));
$d = strval(random_int(1000000000000000, 9999999999999999));
$ctimesd = bcmul($c, $d);

$tests_array = [
    [
        "label" => "Addition",
        "operation" => "3+1",
        "expected" => "4"
    ],
    [
        "label" => "Substraction",
        "operation" => "5-3",
        "expected" => "2"
    ],
    [
        "label" => "Multiplication",
        "operation" => "2*3",
        "expected" => "6"
    ],
    [
        "label" => "Division",
        "operation" => "16/2",
        "expected" => "8"
    ],
    [
        "label" => "Braquets and Addition",
        "operation" => "5+(2+4)",
        "expected" => "11"
    ],
    [
        "label" => "Minmax priority",
        "operation" => "123-321",
        "expected" => "-198"
    ],
    [
        "label" => "Addition and multiplication",
        "operation" => "982*67-5",
        "expected" => "65789"
    ],
    [
        "label" => "Multiple operations and braquets",
        "operation" => "5+(8/4+2)-5*7+(2*2)*3",
        "expected" => "-14"
    ],
    [
        "label" => "Big Multiplication",
        "operation" => "6516954198498452165495616519849581949816519849879841651651*65165198495616541984984651651984",
        "expected" => "424678613931993242192380735804898444632036142454818400507304983254637658181782488211025584"
    ],
    [
        "label" => "Big Addition",
        "operation" => "984981120006498797984651006549649841654984984651+65464987984651165498798465116164987651651651",
        "expected" => "985046584994483449150149805014766006642636636302"
    ],
    [
        "label" => "Random Addition",
        "operation" => "$a+$b",
        "expected" => "$aplusb"
    ],
    [
        "label" => "Random Multiplication",
        "operation" => "$c*$d",
        "expected" => "$ctimesd"
    ],
    [
        "label" => "Hexadecimal",
        "operation" => "caca+fade-bac",
        "expected" => "1b9fc",
        "digits" => "0123456789abcdef"
    ],
    [
        "label" => "Binary",
        "operation" => "101010+1001",
        "expected" => "110011",
        "digits" => "01"
    ],
    [
        "label" => "Division with remainder",
        "operation" => "58975/42",
        "expected" => "1404"
    ],
    [
        "label" => "Special Characters",
        "operation" => "bd/b+f",
        "expected" => "ah",
        "digits" => "0abcdefghi"
    ],
    [
        "label" => "Negative substraction",
        "operation" => "39-87",
        "expected" => "-48",
    ],
    [
        "label" => "Minus number",
        "operation" => "-64",
        "expected" => "-64",
    ]
];

exit(tests($tests_array));
