'use strict';

module.exports = require('gulp-load-plugins')(
  {
    lazy: true,
    scope: ['dependencies', 'devDependencies', 'peerDependencies']
  }
);