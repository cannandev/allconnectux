        <picture class="hero-image-embed">
          <source 
            media="(min-width: 1600px)"
            srcset="<?php print $base_path . '/' . $theme_path; ?>/img/hero/landing-page/hero<?php print $image_choice; ?>_xl.jpg">
          <source 
            media="(min-width: 1200px)"
            srcset="<?php print $base_path . '/' . $theme_path; ?>/img/hero/landing-page/hero<?php print $image_choice; ?>_lg.jpg">  
          <source 
            media="(min-width: 768px)"
            srcset="<?php print $base_path . '/' . $theme_path; ?>/img/hero/landing-page/hero<?php print $image_choice; ?>_md.jpg">
          <source 
            media="(min-width: 480px)"
            srcset="<?php print $base_path . '/' . $theme_path; ?>/img/hero/landing-page/hero<?php print $image_choice; ?>_sm.jpg">            
          <img 
            src="<?php print $base_path . '/' . $theme_path; ?>/img/hero/landing-page/hero<?php print $image_choice; ?>_sm.jpg" 
            alt="Find Offers In Your Area">
        </picture><!-- /picturefill -->  