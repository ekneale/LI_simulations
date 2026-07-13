photonsperpulse=10000
wavelengths=365.0
pulsewidths=10.0
pulses=100

for laserIdx in {0..121}
do
    diffuserIdx=$laserIdx
    wl=$wavelengths
    ppp=$photonsperpulse
    pw=$pulsewidths
    npulse=$pulses

    SETUP_DIR=/data2/kneale/hk-software/LI_simulations/spe_simulations

    BASE_DATA_DIR=/data2/kneale/hk-software/spe_sims/diffuser_${diffuserIdx}

    hadd -f ${BASE_DATA_DIR}/reduced_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp.root  ${BASE_DATA_DIR}/reduced_diffuser_${diffuserIdx}_${wl}_nm_${pw}_ns_${ppp}_ppp_*.root

done
