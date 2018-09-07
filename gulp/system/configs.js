'use strict';

var plugin = require('../helpers/plugins'),
    sysMsg = require('./messages');

module.exports = {
    sass: {
        errLogToConsole: true,
        outputStyle: 'expanded'
    },

    postCSS: {
        native:[
            require('postcss-fixes')(),
            require('postcss-flexboxfixer'),
            require('postcss-flexibility'),
            require('postcss-discard-duplicates')
        ],
        pleeease: {
            "browsers": ["last 4 versions"],
            "minifier": false,
            "mqpacker": false,
        }
    }
}
