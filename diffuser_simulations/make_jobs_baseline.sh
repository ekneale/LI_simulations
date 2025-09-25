
photonsperpulse=(5500000 5500000 5500000 5500000 5500000 5500000)
wavelengths=(365.0 365.0 365.0 365.0 365.0 365.0)
pulsewidths=(10.0 10.0 10.0 10.0 10.0 10.0)
pulses=(1 1 1 1 1 1)
diffusers=(41 62 93 97 116 117)

for laserIdx in {0..5}
do
    diffuserIdx=${diffusers[laserIdx]}
    wl=${wavelengths[laserIdx]}
    ppp=${photonsperpulse[laserIdx]}
    pw=${pulsewidths[laserIdx]}
    npulse=${pulses[laserIdx]}

    BASE_DATA_DIR=/data2/kneale/hk-software/diffuser_sims/diffuser_${diffuserIdx}
    if [ ! -e $BASE_DATA_DIR ];
    then
        mkdir $BASE_DATA_DIR;
    fi
    if [ ! -e $BASE_DATA_DIR/logs ];
    then
        mkdir $BASE_DATA_DIR/logs;
    fi
    cp $BASE_DATA_DIR/../params_0.9_0.75_1.30.mac $BASE_DATA_DIR/params_0.9_0.75_1.30.mac

    cp $BASE_DATA_DIR/../job_diffuser_1_0.9_0.75_1.30.sh $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    cp $BASE_DATA_DIR/../condor_diffuser_1.sub $BASE_DATA_DIR/condor_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sub

    # change the file names in the job script
    sed -i "s/\/macro_diffuser_1_0.9_0.75_1.30.mac/\/macro_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_\${CONDOR_JOB_NUM}.mac/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/\/diffuser_1_0.9_0.75_1.30.root/\/diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_\${CONDOR_JOB_NUM}.root/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/reduced_diffuser_1_0.9_0.75_1.30.root/reduced_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_\${CONDOR_JOB_NUM}.root/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/\$BASE_DATA_DIR\/diffuser_1/\$BASE_DATA_DIR\/diffuser_${diffuserIdx}/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/injectorIdx 1/injectorIdx ${diffuserIdx}/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/injectorWavelength 400/injectorWavelength ${wl}/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/injectorPulseWidth 2/injectorPulseWidth ${pw}/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/nphotons 2/nphotons ${ppp}/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh
    sed -i "s/beamOn 2/beamOn ${npulse}/g" $BASE_DATA_DIR/job_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sh

    # change the condor submission script
    sed -i "s/diffuser_1_0.9_0.75_1.30/diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp/" $BASE_DATA_DIR/condor_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sub
    sed -i "s/diffuser_1_job/diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp/" $BASE_DATA_DIR/condor_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.sub

done;
