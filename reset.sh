#sterg tot ce e de forma *_rata_*, *_putere_*, *_dup_*
while read line 
do
   ONE=`echo $line | cut -d'_' -f1`
   TWO=`echo $line | cut -d'_' -f2`

  rm ${ONE}_rata_${TWO}.txt
  echo S-a sters fisierul ${ONE}_rata_${TWO}.txt ... > reset.txt
  rm ${ONE}_putere_${TWO}.txt
  echo S-a sters fisierul ${ONE}_putere_${TWO}.txt ... >> reset.txt
  rm ${ONE}_dup_${TWO}.txt
  echo S-a sters fisierul ${ONE}_dup_${TWO}.txt ... >> reset.txt

done < toate_testele.txt

#sterg toate folderele, le iau din fisierul ses.txt
while read line 
do
   sudo rm -r ${line}
   echo S-a sters folderul ${line} ... >> reset.txt
done < ses


#sterg si celelalte fisiere
rm aux.txt
echo S-a sters fisierul aux.txt... >> reset.txt

rm rezultate_partiale.txt
echo S-a sters fisierul rezultate_partiale.txt ... >> reset.txt

rm rezultate_finale.txt
echo S-a sters fisierul rezultate_finale.txt ... >> reset.txt

rm nr_deja_reluate.txt
echo S-a sters fisierul nr_deja_reluate.txt ... >> reset.txt

rm se_testeaza_acum.txt
echo S-a sters fisierul se_testeaza_acum.txt ... >> reset.txt

rm toate_testele.txt
echo S-a sters fisierul toate_testele.txt... >> reset.txt

rm nr_retestari.txt
echo S-a sters fisierul nr_retestari.txt ... >> reset.txt

rm plot_file.txt
echo S-a sters fisierul plot_file.txt ... >> reset.txt

rm rez_partiale.txt
echo S-a sters fisierul rez_partiale.txt ... >> reset.txt

rm data.txt
echo S-a sters fisierul data.txt ... >> reset.txt

rm tshark.txt
echo S-a sters fisierul tshark.txt ... >> reset.txt

rm client
echo S-a sters fisierul client ... >> reset.txt

rm server
echo S-a sters fisierul server ... >> reset.txt

rm listeaza
echo S-a sters fisierul listeaza ... >> reset.txt

rm rateAndPower
echo S-a sters fisierul rateAndPower... >> reset.txt

rm putere_si_rata.txt
echo S-a sters fisierul putere_si_rata.txt ... >> reset.txt

rm incaperi.txt
echo S-a sters fisierul incaperi.txt ... >> reset.txt

rm cumuleaza
echo S-a sters fisierul cumuleaza ... >> reset.txt

rm listeaza
echo S-a sters fisierul listeaza ... >> reset.txt

rm indice_final
echo S-a sters fisierul indice_final ... >> reset.txt

rm top3
echo S-a sters fisierul top3... >> reset.txt

rm top3.txt
echo S-a sters fisierul top3.txt ... >> reset.txt

rm dup
echo S-a sters fisierul dup... >> reset.txt

rm c1.wmv
echo S-a sters fisierul c1.wmv ... >> reset.txt

rm f
echo S-a sters fisierul f ... >> reset.txt

rm myapp-bin
echo S-a sters fisierul myapp-bin ... >> reset.txt


rm data.png
echo S-a sters fisierul data.png ... >> reset.txt


rm plot.txt
echo S-a sters fisierul plot.txt ... >> reset.txt

rm rez_partiale.txt
echo S-a sters fisierul rez_partiale.txt ... >> reset.txt

rm rezultate_partiale.txt
echo S-a sters fisierul rezultate_partiale.txt... >> reset.txt

rm rezultate_finale.txt
echo S-a sters fisierul rezultate_finale.txt ... >> reset.txt


rm putere_si_rata.txt
echo S-a sters fisierul putere_si_rata.txt ... >> reset.txt

rm ses
echo S-a sters fisierul ses ... >> reset.txt

echo Resetarea a fost efectuata cu succes! >> reset.txt 

#reinitializez numarul sesiunii
sudo echo 1 > nr_sesiunii.txt

