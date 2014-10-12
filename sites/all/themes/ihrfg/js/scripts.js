$(document).ready(function() {
   $("div.tabs ul.primary li").each(function(i) {
   $(this).addClass("tabid" + (i+1));
   });
});