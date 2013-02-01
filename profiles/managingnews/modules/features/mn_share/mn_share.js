Drupal.behaviors.mn_share = function() {
  $('a.mn-share:not(.processed)').each(function() {
    $(this).addClass('processed').click(function() {
      // Cleanup any existing popups.
      $('div.mn-share-popup').remove();

      // Make an AJAX call for this link.
      var title = $(this).attr('title');
      var url = $(this).attr('href');
      var ajax_url = Drupal.settings.basePath + 'mn-share';
      $.get(ajax_url, {'title': title, 'url': url}, function(data) {
        $(document.body).append(data);
        $('div.mn-share-popup').show()
        .children('span.close').click(function() {
          $('div.mn-share-popup').remove();
        });
      });
      return false;
    });
  });
};
