import matplotlib.pyplot as plt

rayff_val1 = []
rayff_val_err1 = []
rayff_chi1 = []
rayff_err1 = []

rayff_val2 = []
rayff_val_err2 = []
rayff_chi2 = []
rayff_err2 = []

absff_val1 = []
absff_val_err1 = []
absff_chi1 = []
absff_err1 = []

absff_val2 = []
absff_val_err2 = []
absff_chi2 = []
absff_err2 = []

reflf_val1 = []
reflf_val_err1 = []
reflf_chi1 = []
reflf_err1 = []

reflf_val2 = []
reflf_val_err2 = []
reflf_chi2 = []
reflf_err2 = []

# TODO loop over the angles simulated

# Get values for first collimator angle
for line in open("colBottom/collim_1.35/results/scan_reduced_chi_sq_colBottom_barrelPMTs.txt","r"):
  print(line)
  vals = (line.strip().split(", "))

  if "rayff" in line:
    chi2 = float(vals[2])
    if chi2 > 100000: continue
    rayff_val1.append( ((float(vals[0].strip(".root").split("_")[-1])/0.75)-1.0)*100.0 )
    rayff_chi1.append( float(vals[2]) )
    rayff_err1.append(float(vals[3]))
    print(rayff_val1[-1], rayff_chi1[-1] ,rayff_err1[-1])

  if "abwff" in line:
    chi2 = float(vals[2])
    if chi2 > 100000: continue
    absff_val1.append( ((float(vals[0].strip(".root").split("_")[-1])/1.30)-1.0)*100.0 )
    absff_chi1.append( float(vals[2]) )
    absff_err1.append(float(vals[3]))
    print(absff_val1[-1], absff_chi1[-1] ,absff_err1[-1])

  if "refl" in line:
    chi2 = float(vals[2])
    if chi2 > 100000: continue
    reflf_val1.append( ((float(vals[0].strip(".root").split("_")[-1])/0.9)-1.0)*100.0 )
    reflf_chi1.append( float(vals[2]) )
    reflf_err1.append(float(vals[3]))
    print(reflf_val1[-1], reflf_chi1[-1], reflf_err1[-1] )

# Get values for second collimator angle
for line in open("colBottom/collim_1.35/results/scan_reduced_chi_sq_colBottom_bottomPMTs.txt","r"):
  vals = (line.strip().split(", "))

  if "rayff" in line:
    chi2 = float(vals[2])
    if chi2 > 100000: continue
    rayff_val2.append( ((float(vals[0].strip(".root").split("_")[-1])/0.75)-1.0)*100.0 )
    rayff_chi2.append( float(vals[2]) )
    rayff_err2.append(float(vals[3]))
    print(rayff_val2[-1], rayff_chi2[-1], rayff_err2[-1])

  print(line)
  if "abwff" in line:
    chi2 = float(vals[2])
    if chi2 > 100000: continue
    absff_val2.append( ((float(vals[0].strip(".root").split("_")[-1])/1.30)-1.0)*100.0 )
    absff_chi2.append( float(vals[2]) )
    absff_err2.append(float(vals[3]))
    print(absff_val2[-1], absff_chi2[-1], absff_err2[-1])

  if "refl" in line:
    chi2 = float(vals[2])
    if chi2 > 100000: continue
    reflf_val2.append( ((float(vals[0].strip(".root").split("_")[-1])/0.9)-1.0)*100.0 )
    reflf_chi2.append( float(vals[2]) )
    reflf_err2.append(float(vals[3]))
    print(reflf_val2[-1], reflf_chi2[-1], reflf_err2[-1])

## Plot of scattering
plt.subplot(2,2,1)
plt.errorbar( rayff_val1, rayff_chi1, yerr=rayff_err1, label="barrel PMTs" ,linestyle='none',fmt='o',capsize=3,markersize=2)

plt.errorbar( rayff_val2, rayff_chi2, yerr=rayff_err2, label="bottom PMTs" ,linestyle='none',fmt='o',capsize=3,markersize=2)

plt.yscale("log")
plt.title("Scattering")
plt.xlabel("Percentage Shift")
plt.ylabel("chi2/ndof")
plt.legend()

## Plot of absorption
plt.subplot(2,2,2)
plt.errorbar( absff_val1, absff_chi1, yerr=absff_err1, label="barrel PMTs", linestyle='none' ,fmt='o',capsize=3,markersize=2)

plt.errorbar( absff_val2, absff_chi2, yerr=absff_err2, label="bottom PMTs", linestyle='none' ,fmt='o',capsize=3,markersize=2)

plt.yscale("log")
plt.title("Absorption")
plt.xlabel("Percentage Shift")
plt.ylabel("chi2/ndof")
plt.legend()

## Plot of Tyvek reflectivity
plt.subplot(2,2,3)
plt.errorbar( reflf_val1, reflf_chi1, yerr=reflf_err1, label="barrel PMTs" ,linestyle='none',fmt='o',capsize=3, markersize=2)

plt.errorbar( reflf_val2, reflf_chi2, yerr=reflf_err2, label="bottom PMTs" ,linestyle='none',fmt='o',capsize=3, markersize=2)

plt.yscale("log")
plt.title("Reflectivity")
plt.xlabel("Percentage Shift")
plt.ylabel("chi2/ndof")
plt.legend()

plt.show()
