  <nav class="navbar">
    <div class="container navbar-container">
      <!-- Brand and toggle get grouped for better mobile display -->
      <div class="navbar-header">
        <a href="/" title="Home" rel="home" id="logo" class="navbar-brand">
          <img class="navbar-brand-img" src="<?php print $logo; ?>" alt="Home">
        </a>
        <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbarCollapse" aria-expanded="false">
          <span class="glyphicon glyphicon-menu-hamburger"></span>
        </button>
      </div>

      <!-- Collect the nav links, forms, and other content for toggling -->
      <div class="collapse navbar-collapse" id="navbarCollapse">
        <?php if ($main_menu && !$is_spanish): ?>
          <?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('flex-nav', 'nav-primary')))); ?>
        <?php elseif ($secondary_menu): ?>
          <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('flex-nav', 'nav-primary')))); ?>          
        <?php endif; ?>          
        <ul class="flex-nav order-status-nav">
          <li class="order-status">
            <?php if (!$is_spanish): ?>
            <a href="#">Order Status</a>
            <?php else: ?>
            <a href="#">Estado de la Orden</a>
            <?php endif; ?>
          </li>
          <li class="hidden-xs hidden-sm">
            <a href="#" class="navbar-cart">
              <i>
                <img src="/<?php print $theme_path . '/img/shoppingcart.svg'; ?>" alt="Shopping Cart" class="cart-icon">
              </i>
              <span class="js-cart badge cart-empty">0</span>
            </a>
          </li>
        </ul>
      </div><!-- /.navbar-collapse -->
    </div><!-- /.container-fluid -->
  </nav><!--/.navbar-->