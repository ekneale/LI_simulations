col=2.00
colIdx=1

#for i in 0.975 0.9375 0.9 0.8625 0.825 0.7875 0.78 0.7725 0.765 0.7575 0.7425 0.735 0.7275 0.72 0.7125 0.675 0.6375 0.6 0.5625 0.525 #### rayff
for i in 0.975 0.9 0.825 0.78 0.765 0.7425 0.7275 0.7125 0.6375 0.5625 #### rayff
do
hadd -f collimator_${colIdx}/jobs_col_${col}_rayff_${i}.root collimator_${colIdx}/reduced_collimator_${colIdx}_rayff_${i}_*.root
done

#for i in 0.8955 0.891 0.8865 0.882 0.8775 0.873 0.8685 0.864 0.8595 0.855 0.846 0.837 0.828 0.819 0.81 0.765 0.72 0.63 #### refl
for i in 0.8955 0.8865 0.8775 0.8685 0.8595 0.846 0.828 0.81 0.72 #### refl
do
hadd -f collimator_${colIdx}/jobs_col_${col}_refl_${i}.root collimator_${colIdx}/reduced_collimator_${colIdx}_refl_${i}_*.root
done

#for i in 1.69 1.625 1.56 1.495 1.43 1.365 1.339 1.326 1.313 1.287 1.274 1.261 1.248 1.235 1.17 1.105 1.04 0.975 0.91 #### abwff
for i in 1.69 1.56 1.43 1.326 1.287 1.261 1.235 1.105 0.975 #### abwff
do
hadd -f collimator_${colIdx}/jobs_col_${col}_abwff_${i}.root collimator_${colIdx}/reduced_collimator_${colIdx}_abwff_${i}_*.root
done 

hadd -f collimator_${colIdx}/jobs_col_${col}_baseline.root collimator_${colIdx}/reduced_collimator_${colIdx}_baseline*.root

