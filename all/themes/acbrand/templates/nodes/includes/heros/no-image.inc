  <section class="hero">
    <div class="container">
      <header class="">
        <?php print render($title_prefix); ?>
        <h1 class="hero__title" id="page-title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>
      </header><!-- /.hero-header with image -->
    </div>
  </section>

  <!-- filters -->
  <section class="filters-wrapper">
    <div class="container">
      <?php include_once path_to_theme() . '/templates/nodes/includes/filters/filter.inc'; ?>
    </div>
  </section>
