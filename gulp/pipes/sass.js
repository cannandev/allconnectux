'use strict';


var plugin = require('../helpers/plugins'),
    configs = require('../system/configs'),
    sysMsg = require('../system/messages'),
    combine = require('stream-combiner');


module.exports = sassPipe;

function sassPipe() {
  return combine([].concat(
      plugin.sourcemaps.init(),
      plugin.sass({
        errLogToConsole: true,
        outputStyle: 'expanded'
      }),
      plugin.pleeease(configs.postCSS.pleeease),
      plugin.postcss(configs.postCSS.native),
      plugin.csscomb(),
      plugin.notify(sysMsg.success)
    )
  )
}