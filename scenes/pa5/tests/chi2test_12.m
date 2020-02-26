obsFrequencies = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
expFrequencies = [ -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7200, -7199.99, -7200, -7200, -7199.99, -7200, -7200; -5600, -5600, -5600, -5600, -5600, -5600, -5600, -5600, -5599.96, -5199.58, 1056.88, -5540.07, -5600, -5600, -5599.99, -5600, -5600, -5599.99, -5600, -5600; -4000, -4000, -4000, -4000, -4000, -4000, -4000, -3998.33, -3801.39, 762.681, 8454.58, -1496.24, -3932.64, -3999.61, -3999.99, -4000, -4000, -4000, -4000, -4000; -2400, -2400, -2400, -2400, -2399.99, -2399.6, -2389.01, -2189.57, -222.779, 6898.45, 11474.9, 4658.5, -1113.6, -2296.49, -2395.19, -2399.83, -2399.99, -2400, -2400, -2400; -799.936, -799.905, -799.75, -798.944, -793.797, -757.448, -517.049, 708.635, 4601.49, 10712.9, 13321.1, 9192.52, 3277.08, 213.016, -623.674, -774.166, -796.15, -799.297, -799.815, -799.919; 808.027, 810.192, 818.472, 844.955, 934.131, 1238.45, 2187.22, 4562.31, 8725.21, 13070.3, 14604.4, 12107.9, 7531.64, 3773.25, 1842.51, 1122.86, 899.948, 834.944, 815.37, 809.251; 2525.42, 2546, 2613.08, 2774.65, 3147.36, 3970.89, 5612.97, 8337.14, 11767.5, 14645.1, 15565.6, 14046, 10877.3, 7538.76, 5092.32, 3697.37, 3020.87, 2719.37, 2589.59, 2537.27; 4678.31, 4746.24, 4946.11, 5347.23, 6073.46, 7291.11, 9127.68, 11497.6, 13949.2, 15761.1, 16309.2, 15397.2, 13350.2, 10856.6, 8596.11, 6922.45, 5847.07, 5219.15, 4879.25, 4717.89; 7644.87, 7762.1, 8083.5, 8652.89, 9527.27, 10745.3, 12272.8, 13948, 15478.2, 16524.1, 16829.7, 16318.6, 15118.4, 13518.2, 11857.4, 10399.8, 9270.76, 8479.88, 7979.45, 7713.74; 11829.3, 11933.5, 12204.9, 12643.5, 13241.3, 13970.3, 14773.2, 15560.3, 16221.2, 16649.6, 16771.9, 16566.7, 16069.8, 15365.7, 14564.3, 13773, 13073.7, 12515.1, 12119.2, 11890.9 ];
colormap(jet);
clf; subplot(2,1,1);
imagesc(obsFrequencies);
title('Observed frequencies');
axis equal;
subplot(2,1,2);
imagesc(expFrequencies);
axis equal;
title('Expected frequencies');