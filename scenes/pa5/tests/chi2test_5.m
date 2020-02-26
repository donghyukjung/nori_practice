obsFrequencies = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
expFrequencies = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4.63566e-28, 7.35834e-27, 2.79763e-34, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5.32625e-43, 6.48113e-25, 8.05344e-17, 5.7166e-16, 4.04376e-20, 5.57396e-34, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6.44477e-41, 3.89264e-25, 2.30952e-14, 2.63002e-09, 1.11558e-08, 1.81004e-11, 9.61146e-20, 1.71109e-33, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 7.99239e-37, 1.60268e-24, 1.96512e-14, 1.85936e-07, 0.000559479, 0.00171476, 1.64614e-05, 5.77742e-11, 8.84255e-20, 3.00596e-31, 0; 8.61369e-36, 0, 0, 0, 0, 0, 0, 1.86944e-39, 6.88873e-31, 3.94781e-22, 4.98059e-14, 2.49268e-07, 0.0138869, 4.17369, 10.0969, 0.324784, 5.43588e-05, 6.82364e-11, 1.83654e-18, 4.92119e-27; 6.23238e-21, 3.99793e-26, 2.61712e-30, 5.85894e-33, 1.7417e-33, 1.09508e-31, 4.15671e-28, 2.73008e-23, 9.08771e-18, 4.27499e-12, 8.36904e-07, 0.0238569, 41.1253, 2370.72, 4688.41, 375.259, 0.916395, 9.90402e-05, 1.04379e-09, 2.82343e-15; 5.69496e-10, 6.21416e-13, 2.81705e-15, 1.04884e-16, 5.62656e-17, 4.97154e-16, 4.73604e-14, 2.54171e-11, 3.78805e-08, 7.68096e-05, 0.110555, 62.0962, 7492.96, 116002, 189469, 32581.7, 630.999, 2.04531, 0.00198998, 1.0576e-06; 1.72051, 0.858658, 0.546755, 0.427415, 0.413291, 0.488466, 0.67723, 1.22567, 3.03749, 10.3908, 115.103, 2099.43, 34947.9, 212469, 297942, 90541.9, 7704.21, 389.633, 27.671, 5.10958 ];
colormap(jet);
clf; subplot(2,1,1);
imagesc(obsFrequencies);
title('Observed frequencies');
axis equal;
subplot(2,1,2);
imagesc(expFrequencies);
axis equal;
title('Expected frequencies');