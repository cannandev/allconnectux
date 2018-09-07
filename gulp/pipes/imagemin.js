'use strict';

var plugin = require('../helpers/');
var Combine = require('stream-combiner');

module.exports = imageminPipe;

function imageminPipe() {
  return Combine(
    plugin.imagemin()
  )
}