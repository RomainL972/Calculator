#!/usr/bin/env php
<?php
function run($operation, $expected, $digits="0123456789") {
    $descriptorspec = array(
       0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
       1 => array("pipe", "w")  // stdout is a pipe that the child will write to
    );

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
    $success = 1;
    foreach ($array as $test) {
        $message = $test["label"] . ": ";
        if(!array_key_exists("digits", $test)) $test["digits"] = "0123456789";
        if(run($test["operation"], $test["expected"], $test["digits"]))
            echo $message . "SUCCESS\n";
        else {
            echo $message . "FAILURE\n";
            $success = 0;
        }
    }
    return $success;
}

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
        "operation" => "5+(8*4+2)-5*7+(2*2)*3",
        "expected" => "16"
    ]
];

return tests($tests_array);
