        <picture class="hero-image-embed">
          <source 
            media="(min-width: 1600px)"
            srcset="<?php print $theme_path; ?>/img/hero/hero<?php print $image_choice; ?>_xl.jpg">
          <source 
            media="(min-width: 1200px)"
            srcset="<?php print $theme_path; ?>/img/hero/hero<?php print $image_choice; ?>_lg.jpg">  
          <source 
            media="(min-width: 768px)"
            srcset="<?php print $theme_path; ?>/img/hero/hero<?php print $image_choice; ?>_md.jpg">
          <source 
            media="(min-width: 480px)"
            srcset="<?php print $theme_path; ?>/img/hero/hero<?php print $image_choice; ?>_sm.jpg">            
          <source 
            media="(min-width: 320px)"
            srcset="<?php print $theme_path; ?>/img/hero/hero<?php print $image_choice; ?>_xs.jpg"> 
          <img 
            src="<?php print $theme_path; ?>/img/hero/hero<?php print $image_choice; ?>_xs.jpg" 
            alt="Find Offers In Your Area">
        </picture><!-- /picturefill -->  