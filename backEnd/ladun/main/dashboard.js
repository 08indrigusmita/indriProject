$(document).ready(function(){
  let loading = "Memuat halaman ...";
  $('#divUtama').html(loading);
  $('#divUtama').load('/admin/beranda');


  $('#btnBeranda').click(function(){
    $('#divUtama').html(loading);
    $('#divUtama').load('/admin/beranda');
  });

  $('#btnTitikPersimpangan').click(function(){
    $('#divUtama').html(loading);
    $('#divUtama').load('/admin/titikPersimpangan');
  });

  $('#btnLogOut').click(function(){
    window.location.assign('/admin/logOut');
  });

});
