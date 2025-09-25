colIdx=1
BASE_DATA_DIR=/data2/kneale/hk-software/collimator_sims/collimator_${colIdx}

if [ ! -e $BASE_DATA_DIR ];
then
    mkdir $BASE_DATA_DIR;
fi

#for i in 1.69 1.625 1.56 1.495 1.43 1.365 1.352 1.339 1.326 1.313 1.287 1.274 1.261 1.248 1.235 1.17 1.105 1.04 0.975 0.91 #### abwff#
for i in 1.69 1.56 1.43 1.352 1.326 1.287 1.261 1.235 1.105 0.975 #### abwff#

do

	cp $BASE_DATA_DIR/../params_0.9_0.75_1.30.mac $BASE_DATA_DIR/params_abwff_${i}.mac

	# change the abwff value in the params file
        echo "editing the params file"
	sed -i "s/abwff\s1.30/abwff $i/" $BASE_DATA_DIR/params_abwff_${i}.mac


	for j in {0..9}
	do
	    file=$BASE_DATA_DIR/reduced_collimator_${colIdx}_abwff_${i}_${j}.root
	    if [ -f "$file" ]; then
		echo "$file exists"
	    else
                echo "editing the script and macro"
                cp $BASE_DATA_DIR/../macro_collimator_1_0.9_0.75_1.30.mac $BASE_DATA_DIR/macro_collimator_${colIdx}_abwff_${i}_${j}.mac
                cp $BASE_DATA_DIR/../job_collimator_1_0.9_0.75_1.30.sh $BASE_DATA_DIR/job_collimator_${colIdx}_abwff_${i}_${j}.sh
                cp $BASE_DATA_DIR/../condor_collimator_1.sub $BASE_DATA_DIR/condor_collimator_${colIdx}_abwff_${i}_${j}.sub

		# change the seed and the wcsim output filename in the macro
		sed -i "s/seed 3254/seed 3254$j/" $BASE_DATA_DIR/macro_collimator_${colIdx}_abwff_${i}_${j}.mac
		sed -i "s/collimator_1_0.9_0.75_1.30.root/collimator_${colIdx}_abwff_${i}_${j}.root/" $BASE_DATA_DIR/macro_collimator_${colIdx}_abwff_${i}_${j}.mac
                sed -i "s/injectorIdx 1/injectorIdx ${colIdx}/g" $BASE_DATA_DIR/macro_collimator_${colIdx}_abwff_${i}_${j}.mac

		# change the file names in the job script
		sed -i "s/params_0.9_0.75_1.30/params_abwff_${i}/g" $BASE_DATA_DIR/job_collimator_${colIdx}_abwff_${i}_${j}.sh
		sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${colIdx}_abwff_${i}_${j}/g" $BASE_DATA_DIR/job_collimator_${colIdx}_abwff_${i}_${j}.sh
                sed -i "s/collimator_1/collimator_${colIdx}/g" $BASE_DATA_DIR/job_collimator_${colIdx}_abwff_${i}_${j}.sh

		# change the condor submission script
                sed -i "s/collimator_1_0.9_0.75_1.30/collimator_${colIdx}_abwff_${i}_${j}/" $BASE_DATA_DIR/condor_collimator_${colIdx}_abwff_${i}_${j}.sub
                sed -i "s/collimator_1_job/col_${colIdx}_abwff_${i}_${j}/" $BASE_DATA_DIR/condor_collimator_${colIdx}_abwff_${i}_${j}.sub

	    fi
	done;
 #   fi
done;
