'use strict';

// Reusable task function to compile styles

var helper = require('../helpers');
var paths = require('../helpers/paths');
var pipe = require('../pipes');

module.exports = function styleCompile (dir) {
  return helper.buildTask((dir + paths.inputs.scss), pipe.sass, (dir + paths.outputs.css))
}
