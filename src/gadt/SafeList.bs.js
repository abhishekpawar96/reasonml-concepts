// Generated by BUCKLESCRIPT, PLEASE EDIT WITH CARE
'use strict';


function length(param) {
  if (param) {
    return 1 + length(param[0][1]) | 0;
  } else {
    return 0;
  }
}

function head(param) {
  return param[0][0];
}

exports.length = length;
exports.head = head;
/* No side effect */