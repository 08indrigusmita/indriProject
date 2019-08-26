//DASBOR.JS
//Core file js - Apps Perpustakaan SD Negeri 101898 Lubuk Pakam
//Project : Apps Perpustakaan SD Negeri 101898 Lubuk Pakam
//Programmer : Aditia Darma Nasution
//Team : PixelKreatif

$(document).ready(function(){
				var loading = "<i class='fa fa-spin fa-refresh'></i>";
        console.log("Halaman selesai di load ...");
				$('#conUtama').html(loading + " Memuat halaman ...");
        $('#capMenu').html("Statistik Aplikasi");
        $('#conUtama').load('beranda.php');
        //start -> aksi tombol beranda
        $('#tblBeranda').click(function(){
          $('#conUtama').html(loading + " Memuat halaman ...");
          $('#conUtama').load('beranda.php');
        });

        $('#btnDevice').click(function(){
					$('#conUtama').html(loading + " Memuat halaman ...");
          $('#conUtama').load('device.php');
				});

				function refreshBeranda()
				{
					$('#conUtama').load('beranda.php');
				}
				// setInterval(refreshBeranda, 4000);
});
