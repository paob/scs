/*! \page page_benchmark_results Benchmarks
 * 
 * \tableofcontents
 * 
 * \section benchmarks-dolan-more Dolan-Moré performance profiles
 * 
 * In order to compare different solvers, we employ the [Dolan-Moré performance 
 * profile plot](https://pdfs.semanticscholar.org/54a2/0dbd409436be4f188dfa9a78949a1cac230d.pdf).
 * 
 * Let us briefly introduce the Dolan-Moré performance profile plot. 
 * 
 * Let \f$P\f$ be a finite set of problems used as benchmarks and \f$S\f$ be a 
 * set of solvers we want to compare to one another.
 * 
 * Let \f$t_{p,s}\f$ be the computing cost (e.g., time of flops) to solve a problem 
 * \f$p\f$ using a solver \f$s\f$.
 * 
 * We define the ration between \f$t_{p,s}\f$ and the lowest observed cost to solve
 * this problem using some solver \f$s\in S\f$:
 * 
 * \f{eqnarray*}{
 * r_{p,s} = \frac{t_{p,s}}{\min_{s \in S} t_{p,s}}.
 * \f}
 * 
 * If a solver \f$s\f$ does not solve a problem \f$p\f$, then we assign to \f$r_{p,s}\f$
 * a very high value \f$r_M > r_{p,s}\f$ for all other \f$p,s\f$.
 * 
 * The cumulative distribution of the performance ratio is the Dolan-Moré performance 
 * profile plot.
 * 
 * In particular, define
 * 
 * \f{eqnarray*}{
 * \rho_s(\tau) = \frac{1}{n_p}\#\{p\in P: r_{p,s}\leq \tau\},
 * \f}
 * 
 * for \f$\tau\geq 1\f$ and where \f$n_p\f$ is the number of problems.
 * 
 * The Dolan-Moré performance profile is the plot of \f$\rho_s\f$ vs \f$\tau\f$,
 * typically on a logarithmic x-axis.
 *
 * \section benchmark-results Benchmark results 
 * 
 * In all benchmark results presented below we set the tolerance of \f$10^{-4}\f$.
 * 
 * \subsection benchmarks-lasso LASSO problems 
 * 
 * [1152 lasso problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_lasso.m)
 * 
 *
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-broyden-50.png" alt="lasso-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-broyden-100.png" alt="lasso-broyden-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/lasso/lasso-anderson-10-15.png" alt="lasso-anderson-10-15" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 *  
 * \subsection benchmarks-pca1 Regularized PCA
 * 
 * [288 regularized PCA problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_pca.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-broyden-100.png" alt="pca-broyden-100" width="93%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-anderson-15.png" alt="pca-anderson-15" width="100%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/pca/pca-anderson-20.png" alt="pca-anderson-20" width="93%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 *  
 * \subsection benchmarks-logreg Logistic regression problems
 * 
 * [288 logistic regression problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_logreg.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-broyden-50-100.png" alt="logreg-broyden-50-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-5.png" alt="logreg-anderson-5" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/logreg/logreg-anderson-10.png" alt="logreg-anderson-10" width="95%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \subsection benchmarks-sdp2 Semidefinite programming
 * 
 * [36 SDP problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_sdp2.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-broyden-50.png" alt="sdp-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-anderson-10.png" alt="sdp2-anderson-10" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/sdp2/sdp2-anderson-15.png" alt="sdp2-anderson-15" width="90%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \subsection benchmarks-normcon Norm-constrained norm minimization
 * 
 * [384 norm-constrained problems](https://github.com/kul-forbes/scs/blob/master/tests/profiling_matlab/profile_runners/profile_runner_normcon.m)
 * 
 * <div>
 * <table border="0">
 *  <tr>
 *      <td style="padding:1px">
 *          <img src="images/normcon/normcon-broyden-50.png" alt="normcon-broyden-50" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/normcon/normcon-broyden-100.png" alt="normcon-broyden-100" width="95%"/>
 *      </td>
 *      <td style="padding:1px">
 *          <img src="images/normcon/normcon-anderson-5.png" alt="normcon-anderson-5" width="90%"/>
 *      </td>
 *  </tr>
 * </table>
 * </div>
 * 
 * \section maros-meszaros Maros-Meszaros Problems
 * 
 * We tested SuperSCS on the 
 * [Maros-Meszaros collection of QP problems](http://www.cuter.rl.ac.uk/Problems/marmes.html).
 * 
 * \subsection mm-with-svd Using SVD in AA
 * [[RAW DATA (with SVD)]](data/maros-meszaros-01.txt)
 * <div>
 *  <table>
 *  <tr>
 *   <th>PROBLEM</th>
 *   <th><span title="SCS">SCS</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:3</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:5</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:10</span></th>
 *   <th><span title="(k0,k1,k2)=(0,1,1), ls=10">Broyden, mem:50</span></th>
 *   <th><span title="(k0,k1,k2)=(0,1,1), ls=10">Broyden, mem:100</span></th>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2D.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2D</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">7856.9</span> (<span title="iterations">312</span>)</td>
 *   <td><span title="runtime in milliseconds">3261.4</span> (<span title="iterations">128</span>)</td>
 *   <td><span title="runtime in milliseconds">3973.2</span> (<span title="iterations">162</span>)</td>
 *   <td><span title="runtime in milliseconds">5534.1</span> (<span title="iterations">185</span>)</td>
 *   <td><span title="runtime in milliseconds">24386.1</span> (<span title="iterations">599</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DC.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DC</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">2693.6</span> (<span title="iterations">113</span>)</td>
 *   <td><span title="runtime in milliseconds">2648.9</span> (<span title="iterations">113</span>)</td>
 *   <td><span title="runtime in milliseconds">6704.3</span> (<span title="iterations">217</span>)</td>
 *   <td><span title="runtime in milliseconds">5462.8</span> (<span title="iterations">169</span>)</td>
 *   <td><span title="runtime in milliseconds">3653.4</span> (<span title="iterations">111</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DCQP.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DCQP</a></td>
 *   <td><span title="runtime in milliseconds">579.8</span> (<span title="iterations">99</span>)</td>
 *   <td><span title="runtime in milliseconds">350.3</span> (<span title="iterations">32</span>)</td>
 *   <td><span title="runtime in milliseconds">384.6</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">479.9</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">618.4</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">603.6</span> (<span title="iterations">37</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3D.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3D</a></td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">0</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DC.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DC</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">119.6</span> (<span title="iterations">100</span>)</td>
 *   <td><span title="runtime in milliseconds">23.0</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">58.8</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">81.7</span> (<span title="iterations">65</span>)</td>
 *   <td><span title="runtime in milliseconds">271.4</span> (<span title="iterations">156</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DCQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DCQP</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">1208.6</span> (<span title="iterations">607</span>)</td>
 *   <td><span title="runtime in milliseconds">1023.4</span> (<span title="iterations">377</span>)</td>
 *   <td><span title="runtime in milliseconds">1521.6</span> (<span title="iterations">415</span>)</td>
 *   <td><span title="runtime in milliseconds">491.8</span> (<span title="iterations">195</span>)</td>
 *   <td><span title="runtime in milliseconds">991.7</span> (<span title="iterations">277</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DQP</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">510.2</span> (<span title="iterations">162</span>)</td>
 *   <td><span title="runtime in milliseconds">901.0</span> (<span title="iterations">229</span>)</td>
 *   <td><span title="runtime in milliseconds">753.7</span> (<span title="iterations">160</span>)</td>
 *   <td><span title="runtime in milliseconds">821.4</span> (<span title="iterations">184</span>)</td>
 *   <td><span title="runtime in milliseconds">2833.9</span> (<span title="iterations">466</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-050.SIF" title="2597 vars, 2401 eqs, 2401 ineqs">CONT-050</a></td>
 *   <td><span title="runtime in milliseconds">935.5</span> (<span title="iterations">1157</span>)</td>
 *   <td><span title="runtime in milliseconds">1671.5</span> (<span title="iterations">770</span>)</td>
 *   <td><span title="runtime in milliseconds">1969.2</span> (<span title="iterations">786</span>)</td>
 *   <td><span title="runtime in milliseconds">2759.2</span> (<span title="iterations">757</span>)</td>
 *   <td><span title="runtime in milliseconds">4239.5</span> (<span title="iterations">1515</span>)</td>
 *   <td><span title="runtime in milliseconds">4449.8</span> (<span title="iterations">1184</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-100.SIF" title="10197 vars, 9801 eqs, 9801 ineqs">CONT-100</a></td>
 *   <td><span title="runtime in milliseconds">5803.7</span> (<span title="iterations">1656</span>)</td>
 *   <td><span title="runtime in milliseconds">8912.9</span> (<span title="iterations">960</span>)</td>
 *   <td><span title="runtime in milliseconds">10272.0</span> (<span title="iterations">949</span>)</td>
 *   <td><span title="runtime in milliseconds">19014.3</span> (<span title="iterations">1146</span>)</td>
 *   <td><span title="runtime in milliseconds">27125.9</span> (<span title="iterations">1995</span>)</td>
 *   <td><span title="runtime in milliseconds">33595.4</span> (<span title="iterations">1931</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DPKLO1.SIF" title="133 vars, 77 eqs, 77 ineqs">DPKLO1</a></td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">3</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL1.SIF" title="85 vars, 1 eqs, 1 ineqs">DUAL1</a></td>
 *   <td><span title="runtime in milliseconds">7.9</span> (<span title="iterations">65</span>)</td>
 *   <td><span title="runtime in milliseconds">10.2</span> (<span title="iterations">42</span>)</td>
 *   <td><span title="runtime in milliseconds">11.0</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">16.7</span> (<span title="iterations">53</span>)</td>
 *   <td><span title="runtime in milliseconds">12.2</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">11.7</span> (<span title="iterations">45</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL2.SIF" title="96 vars, 1 eqs, 1 ineqs">DUAL2</a></td>
 *   <td><span title="runtime in milliseconds">12.5</span> (<span title="iterations">82</span>)</td>
 *   <td><span title="runtime in milliseconds">14.0</span> (<span title="iterations">59</span>)</td>
 *   <td><span title="runtime in milliseconds">12.6</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">21.0</span> (<span title="iterations">58</span>)</td>
 *   <td><span title="runtime in milliseconds">16.5</span> (<span title="iterations">56</span>)</td>
 *   <td><span title="runtime in milliseconds">15.2</span> (<span title="iterations">52</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL3.SIF" title="111 vars, 1 eqs, 1 ineqs">DUAL3</a></td>
 *   <td><span title="runtime in milliseconds">14.6</span> (<span title="iterations">90</span>)</td>
 *   <td><span title="runtime in milliseconds">13.2</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">15.7</span> (<span title="iterations">57</span>)</td>
 *   <td><span title="runtime in milliseconds">21.8</span> (<span title="iterations">60</span>)</td>
 *   <td><span title="runtime in milliseconds">15.0</span> (<span title="iterations">42</span>)</td>
 *   <td><span title="runtime in milliseconds">15.0</span> (<span title="iterations">42</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL4.SIF" title="75 vars, 1 eqs, 1 ineqs">DUAL4</a></td>
 *   <td><span title="runtime in milliseconds">5.1</span> (<span title="iterations">64</span>)</td>
 *   <td><span title="runtime in milliseconds">7.3</span> (<span title="iterations">35</span>)</td>
 *   <td><span title="runtime in milliseconds">5.5</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">11.9</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">6.6</span> (<span title="iterations">36</span>)</td>
 *   <td><span title="runtime in milliseconds">6.4</span> (<span title="iterations">36</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC1.SIF" title="9 vars, 1 eqs, 215 ineqs">DUALC1</a></td>
 *   <td><span title="runtime in milliseconds">24.1</span> (<span title="iterations">305</span>)</td>
 *   <td><span title="runtime in milliseconds">24.4</span> (<span title="iterations">154</span>)</td>
 *   <td><span title="runtime in milliseconds">22.6</span> (<span title="iterations">136</span>)</td>
 *   <td><span title="runtime in milliseconds">31.8</span> (<span title="iterations">151</span>)</td>
 *   <td><span title="runtime in milliseconds">21.1</span> (<span title="iterations">148</span>)</td>
 *   <td><span title="runtime in milliseconds">12.3</span> (<span title="iterations">84</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC2.SIF" title="7 vars, 1 eqs, 229 ineqs">DUALC2</a></td>
 *   <td><span title="runtime in milliseconds">56.1</span> (<span title="iterations">825</span>)</td>
 *   <td><span title="runtime in milliseconds">30.0</span> (<span title="iterations">214</span>)</td>
 *   <td><span title="runtime in milliseconds">22.5</span> (<span title="iterations">152</span>)</td>
 *   <td><span title="runtime in milliseconds">24.0</span> (<span title="iterations">111</span>)</td>
 *   <td><span title="runtime in milliseconds">16.7</span> (<span title="iterations">109</span>)</td>
 *   <td><span title="runtime in milliseconds">16.8</span> (<span title="iterations">97</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC5.SIF" title="8 vars, 1 eqs, 278 ineqs">DUALC5</a></td>
 *   <td><span title="runtime in milliseconds">172.6</span> (<span title="iterations">1878</span>)</td>
 *   <td><span title="runtime in milliseconds">20.5</span> (<span title="iterations">135</span>)</td>
 *   <td><span title="runtime in milliseconds">14.3</span> (<span title="iterations">82</span>)</td>
 *   <td><span title="runtime in milliseconds">16.1</span> (<span title="iterations">80</span>)</td>
 *   <td><span title="runtime in milliseconds">12.6</span> (<span title="iterations">83</span>)</td>
 *   <td><span title="runtime in milliseconds">11.3</span> (<span title="iterations">71</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC8.SIF" title="8 vars, 1 eqs, 503 ineqs">DUALC8</a></td>
 *   <td><span title="runtime in milliseconds">134.8</span> (<span title="iterations">993</span>)</td>
 *   <td><span title="runtime in milliseconds">57.0</span> (<span title="iterations">275</span>)</td>
 *   <td><span title="runtime in milliseconds">45.5</span> (<span title="iterations">195</span>)</td>
 *   <td><span title="runtime in milliseconds">25.3</span> (<span title="iterations">80</span>)</td>
 *   <td><span title="runtime in milliseconds">24.3</span> (<span title="iterations">100</span>)</td>
 *   <td><span title="runtime in milliseconds">20.0</span> (<span title="iterations">69</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GENHS28.SIF" title="10 vars, 8 eqs, 8 ineqs">GENHS28</a></td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">19</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GOULDQP3.SIF" title="699 vars, 349 eqs, 349 ineqs">GOULDQP3</a></td>
 *   <td><span title="runtime in milliseconds">54.0</span> (<span title="iterations">342</span>)</td>
 *   <td><span title="runtime in milliseconds">150.6</span> (<span title="iterations">316</span>)</td>
 *   <td><span title="runtime in milliseconds">178.4</span> (<span title="iterations">285</span>)</td>
 *   <td><span title="runtime in milliseconds">292.5</span> (<span title="iterations">357</span>)</td>
 *   <td><span title="runtime in milliseconds">85.2</span> (<span title="iterations">145</span>)</td>
 *   <td><span title="runtime in milliseconds">115.7</span> (<span title="iterations">150</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS118.SIF" title="15 vars, 17 ineqs">HS118</a></td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">123</span>)</td>
 *   <td><span title="runtime in milliseconds">4.6</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">4.3</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">5.6</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">2.7</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">3.0</span> (<span title="iterations">46</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS21.SIF" title="2 vars, 1 ineqs">HS21</a></td>
 *   <td><span title="runtime in milliseconds">20.1</span> (<span title="iterations">751</span>)</td>
 *   <td><span title="runtime in milliseconds">3.8</span> (<span title="iterations">59</span>)</td>
 *   <td><span title="runtime in milliseconds">23.1</span> (<span title="iterations">274</span>)</td>
 *   <td><span title="runtime in milliseconds">195.1</span> (<span title="iterations">1206</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">20</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS268.SIF" title="5 vars, 5 ineqs">HS268</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">15</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">18</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35.SIF" title="3 vars, 1 ineqs">HS35</a></td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">1.3</span> (<span title="iterations">15</span>)</td>
 *   <td><span title="runtime in milliseconds">1.3</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">16</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35MOD.SIF" title="3 vars, 1 ineqs">HS35MOD</a></td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">32</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">18</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS51.SIF" title="5 vars, 3 eqs, 3 ineqs">HS51</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS52.SIF" title="5 vars, 3 eqs, 3 ineqs">HS52</a></td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">6</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS53.SIF" title="5 vars, 3 eqs, 3 ineqs">HS53</a></td>
 *   <td><span title="runtime in milliseconds">3.3</span> (<span title="iterations">108</span>)</td>
 *   <td><span title="runtime in milliseconds">3.6</span> (<span title="iterations">69</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">22</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS76.SIF" title="4 vars, 3 ineqs">HS76</a></td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">21</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUES-MOD.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUES-MOD</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">11808.2</span> (<span title="iterations">2859</span>)</td>
 *   <td><span title="runtime in milliseconds">11117.2</span> (<span title="iterations">2183</span>)</td>
 *   <td><span title="runtime in milliseconds">10702.1</span> (<span title="iterations">1385</span>)</td>
 *   <td><span title="runtime in milliseconds">9284.9</span> (<span title="iterations">1733</span>)</td>
 *   <td><span title="runtime in milliseconds">6995.4</span> (<span title="iterations">892</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUESTIS.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUESTIS</a></td>
 *   <td><span title="runtime in milliseconds">26.1</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">53.3</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">30.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">89.3</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">21.5</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">19.9</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/KSIP.SIF" title="20 vars, 1001 ineqs">KSIP</a></td>
 *   <td><span title="runtime in milliseconds">83.8</span> (<span title="iterations">110</span>)</td>
 *   <td><span title="runtime in milliseconds">110.2</span> (<span title="iterations">97</span>)</td>
 *   <td><span title="runtime in milliseconds">110.5</span> (<span title="iterations">89</span>)</td>
 *   <td><span title="runtime in milliseconds">126.9</span> (<span title="iterations">84</span>)</td>
 *   <td><span title="runtime in milliseconds">87.1</span> (<span title="iterations">51</span>)</td>
 *   <td><span title="runtime in milliseconds">85.5</span> (<span title="iterations">51</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LASER.SIF" title="1002 vars, 1000 ineqs">LASER</a></td>
 *   <td><span title="runtime in milliseconds">2107.5</span> (<span title="iterations">4613</span>)</td>
 *   <td><span title="runtime in milliseconds">2106.2</span> (<span title="iterations">2077</span>)</td>
 *   <td><span title="runtime in milliseconds">2365.9</span> (<span title="iterations">2207</span>)</td>
 *   <td><span title="runtime in milliseconds">3931.6</span> (<span title="iterations">2364</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET1.SIF" title="10002 vars, 10000 ineqs">LISWET1</a></td>
 *   <td><span title="runtime in milliseconds">4613.6</span> (<span title="iterations">2761</span>)</td>
 *   <td><span title="runtime in milliseconds">7973.6</span> (<span title="iterations">1461</span>)</td>
 *   <td><span title="runtime in milliseconds">8488.7</span> (<span title="iterations">1340</span>)</td>
 *   <td><span title="runtime in milliseconds">7161.8</span> (<span title="iterations">847</span>)</td>
 *   <td><span title="runtime in milliseconds">8202.9</span> (<span title="iterations">1121</span>)</td>
 *   <td><span title="runtime in milliseconds">23464.1</span> (<span title="iterations">2227</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET10.SIF" title="10002 vars, 10000 ineqs">LISWET10</a></td>
 *   <td><span title="runtime in milliseconds">4437.6</span> (<span title="iterations">2837</span>)</td>
 *   <td><span title="runtime in milliseconds">8256.4</span> (<span title="iterations">1498</span>)</td>
 *   <td><span title="runtime in milliseconds">8717.2</span> (<span title="iterations">1388</span>)</td>
 *   <td><span title="runtime in milliseconds">7500.6</span> (<span title="iterations">883</span>)</td>
 *   <td><span title="runtime in milliseconds">13012.9</span> (<span title="iterations">1741</span>)</td>
 *   <td><span title="runtime in milliseconds">22575.9</span> (<span title="iterations">2182</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET11.SIF" title="10002 vars, 10000 ineqs">LISWET11</a></td>
 *   <td><span title="runtime in milliseconds">4317.1</span> (<span title="iterations">2834</span>)</td>
 *   <td><span title="runtime in milliseconds">7883.3</span> (<span title="iterations">1470</span>)</td>
 *   <td><span title="runtime in milliseconds">8990.5</span> (<span title="iterations">1430</span>)</td>
 *   <td><span title="runtime in milliseconds">7139.9</span> (<span title="iterations">847</span>)</td>
 *   <td><span title="runtime in milliseconds">15755.5</span> (<span title="iterations">2116</span>)</td>
 *   <td><span title="runtime in milliseconds">21567.2</span> (<span title="iterations">2131</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET12.SIF" title="10002 vars, 10000 ineqs">LISWET12</a></td>
 *   <td><span title="runtime in milliseconds">4356.8</span> (<span title="iterations">2833</span>)</td>
 *   <td><span title="runtime in milliseconds">8349.8</span> (<span title="iterations">1529</span>)</td>
 *   <td><span title="runtime in milliseconds">8833.6</span> (<span title="iterations">1406</span>)</td>
 *   <td><span title="runtime in milliseconds">7597.3</span> (<span title="iterations">883</span>)</td>
 *   <td><span title="runtime in milliseconds">14610.8</span> (<span title="iterations">1924</span>)</td>
 *   <td><span title="runtime in milliseconds">21966.8</span> (<span title="iterations">2074</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET2.SIF" title="10002 vars, 10000 ineqs">LISWET2</a></td>
 *   <td><span title="runtime in milliseconds">3544.8</span> (<span title="iterations">2204</span>)</td>
 *   <td><span title="runtime in milliseconds">6519.1</span> (<span title="iterations">1191</span>)</td>
 *   <td><span title="runtime in milliseconds">6603.9</span> (<span title="iterations">1086</span>)</td>
 *   <td><span title="runtime in milliseconds">6250.9</span> (<span title="iterations">736</span>)</td>
 *   <td><span title="runtime in milliseconds">8743.5</span> (<span title="iterations">1149</span>)</td>
 *   <td><span title="runtime in milliseconds">18464.0</span> (<span title="iterations">1780</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET3.SIF" title="10002 vars, 10000 ineqs">LISWET3</a></td>
 *   <td><span title="runtime in milliseconds">2531.5</span> (<span title="iterations">1589</span>)</td>
 *   <td><span title="runtime in milliseconds">4021.2</span> (<span title="iterations">801</span>)</td>
 *   <td><span title="runtime in milliseconds">4765.7</span> (<span title="iterations">763</span>)</td>
 *   <td><span title="runtime in milliseconds">4533.4</span> (<span title="iterations">541</span>)</td>
 *   <td><span title="runtime in milliseconds">8734.8</span> (<span title="iterations">1047</span>)</td>
 *   <td><span title="runtime in milliseconds">11655.0</span> (<span title="iterations">1117</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET4.SIF" title="10002 vars, 10000 ineqs">LISWET4</a></td>
 *   <td><span title="runtime in milliseconds">2019.3</span> (<span title="iterations">1264</span>)</td>
 *   <td><span title="runtime in milliseconds">3266.1</span> (<span title="iterations">672</span>)</td>
 *   <td><span title="runtime in milliseconds">3570.9</span> (<span title="iterations">624</span>)</td>
 *   <td><span title="runtime in milliseconds">3612.1</span> (<span title="iterations">451</span>)</td>
 *   <td><span title="runtime in milliseconds">6796.2</span> (<span title="iterations">873</span>)</td>
 *   <td><span title="runtime in milliseconds">6297.9</span> (<span title="iterations">606</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET5.SIF" title="10002 vars, 10000 ineqs">LISWET5</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">24095.5</span> (<span title="iterations">4211</span>)</td>
 *   <td><span title="runtime in milliseconds">23745.8</span> (<span title="iterations">3532</span>)</td>
 *   <td><span title="runtime in milliseconds">24351.6</span> (<span title="iterations">2607</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET6.SIF" title="10002 vars, 10000 ineqs">LISWET6</a></td>
 *   <td><span title="runtime in milliseconds">3717.6</span> (<span title="iterations">2590</span>)</td>
 *   <td><span title="runtime in milliseconds">7043.1</span> (<span title="iterations">1345</span>)</td>
 *   <td><span title="runtime in milliseconds">8041.5</span> (<span title="iterations">1252</span>)</td>
 *   <td><span title="runtime in milliseconds">6270.1</span> (<span title="iterations">801</span>)</td>
 *   <td><span title="runtime in milliseconds">14589.5</span> (<span title="iterations">1987</span>)</td>
 *   <td><span title="runtime in milliseconds">8406.3</span> (<span title="iterations">861</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET7.SIF" title="10002 vars, 10000 ineqs">LISWET7</a></td>
 *   <td><span title="runtime in milliseconds">4599.4</span> (<span title="iterations">2837</span>)</td>
 *   <td><span title="runtime in milliseconds">8559.1</span> (<span title="iterations">1484</span>)</td>
 *   <td><span title="runtime in milliseconds">8875.8</span> (<span title="iterations">1384</span>)</td>
 *   <td><span title="runtime in milliseconds">8578.4</span> (<span title="iterations">896</span>)</td>
 *   <td><span title="runtime in milliseconds">13094.3</span> (<span title="iterations">1613</span>)</td>
 *   <td><span title="runtime in milliseconds">28381.5</span> (<span title="iterations">2672</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET8.SIF" title="10002 vars, 10000 ineqs">LISWET8</a></td>
 *   <td><span title="runtime in milliseconds">4436.3</span> (<span title="iterations">2837</span>)</td>
 *   <td><span title="runtime in milliseconds">7989.9</span> (<span title="iterations">1470</span>)</td>
 *   <td><span title="runtime in milliseconds">8985.2</span> (<span title="iterations">1400</span>)</td>
 *   <td><span title="runtime in milliseconds">7649.1</span> (<span title="iterations">883</span>)</td>
 *   <td><span title="runtime in milliseconds">10609.3</span> (<span title="iterations">1404</span>)</td>
 *   <td><span title="runtime in milliseconds">20227.6</span> (<span title="iterations">1894</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET9.SIF" title="10002 vars, 10000 ineqs">LISWET9</a></td>
 *   <td><span title="runtime in milliseconds">4445.1</span> (<span title="iterations">2845</span>)</td>
 *   <td><span title="runtime in milliseconds">8074.1</span> (<span title="iterations">1456</span>)</td>
 *   <td><span title="runtime in milliseconds">9087.0</span> (<span title="iterations">1406</span>)</td>
 *   <td><span title="runtime in milliseconds">7391.9</span> (<span title="iterations">857</span>)</td>
 *   <td><span title="runtime in milliseconds">10684.3</span> (<span title="iterations">1401</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP1.SIF" title="2500 vars, 700 ineqs">MOSARQP1</a></td>
 *   <td><span title="runtime in milliseconds">982.9</span> (<span title="iterations">814</span>)</td>
 *   <td><span title="runtime in milliseconds">878.8</span> (<span title="iterations">425</span>)</td>
 *   <td><span title="runtime in milliseconds">972.4</span> (<span title="iterations">411</span>)</td>
 *   <td><span title="runtime in milliseconds">1304.3</span> (<span title="iterations">401</span>)</td>
 *   <td><span title="runtime in milliseconds">598.7</span> (<span title="iterations">194</span>)</td>
 *   <td><span title="runtime in milliseconds">756.9</span> (<span title="iterations">201</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP2.SIF" title="900 vars, 600 ineqs">MOSARQP2</a></td>
 *   <td><span title="runtime in milliseconds">219.8</span> (<span title="iterations">463</span>)</td>
 *   <td><span title="runtime in milliseconds">190.0</span> (<span title="iterations">270</span>)</td>
 *   <td><span title="runtime in milliseconds">187.3</span> (<span title="iterations">227</span>)</td>
 *   <td><span title="runtime in milliseconds">224.1</span> (<span title="iterations">186</span>)</td>
 *   <td><span title="runtime in milliseconds">171.0</span> (<span title="iterations">133</span>)</td>
 *   <td><span title="runtime in milliseconds">188.4</span> (<span title="iterations">124</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/POWELL20.SIF" title="10000 vars, 10000 ineqs">POWELL20</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL1.SIF" title="325 vars, 85 ineqs">PRIMAL1</a></td>
 *   <td><span title="runtime in milliseconds">23.4</span> (<span title="iterations">69</span>)</td>
 *   <td><span title="runtime in milliseconds">20.3</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">21.0</span> (<span title="iterations">41</span>)</td>
 *   <td><span title="runtime in milliseconds">20.8</span> (<span title="iterations">38</span>)</td>
 *   <td><span title="runtime in milliseconds">29.9</span> (<span title="iterations">42</span>)</td>
 *   <td><span title="runtime in milliseconds">27.5</span> (<span title="iterations">42</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL2.SIF" title="649 vars, 96 ineqs">PRIMAL2</a></td>
 *   <td><span title="runtime in milliseconds">16.2</span> (<span title="iterations">32</span>)</td>
 *   <td><span title="runtime in milliseconds">11.5</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">11.4</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">12.3</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">29.2</span> (<span title="iterations">29</span>)</td>
 *   <td><span title="runtime in milliseconds">31.0</span> (<span title="iterations">29</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL3.SIF" title="745 vars, 111 ineqs">PRIMAL3</a></td>
 *   <td><span title="runtime in milliseconds">28.4</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">24.2</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">23.5</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">23.6</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">80.7</span> (<span title="iterations">40</span>)</td>
 *   <td><span title="runtime in milliseconds">77.9</span> (<span title="iterations">40</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL4.SIF" title="1489 vars, 75 ineqs">PRIMAL4</a></td>
 *   <td><span title="runtime in milliseconds">31.8</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">28.8</span> (<span title="iterations">30</span>)</td>
 *   <td><span title="runtime in milliseconds">21.3</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">21.9</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">37.5</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">39.7</span> (<span title="iterations">26</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC1.SIF" title="230 vars, 9 ineqs">PRIMALC1</a></td>
 *   <td><span title="runtime in milliseconds">6.0</span> (<span title="iterations">62</span>)</td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">3.1</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">5.7</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">6.3</span> (<span title="iterations">31</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC5.SIF" title="287 vars, 8 ineqs">PRIMALC5</a></td>
 *   <td><span title="runtime in milliseconds">6.8</span> (<span title="iterations">63</span>)</td>
 *   <td><span title="runtime in milliseconds">10.4</span> (<span title="iterations">40</span>)</td>
 *   <td><span title="runtime in milliseconds">22.9</span> (<span title="iterations">80</span>)</td>
 *   <td><span title="runtime in milliseconds">250.8</span> (<span title="iterations">522</span>)</td>
 *   <td><span title="runtime in milliseconds">13.1</span> (<span title="iterations">57</span>)</td>
 *   <td><span title="runtime in milliseconds">36.2</span> (<span title="iterations">127</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC8.SIF" title="520 vars, 8 ineqs">PRIMALC8</a></td>
 *   <td><span title="runtime in milliseconds">16.6</span> (<span title="iterations">79</span>)</td>
 *   <td><span title="runtime in milliseconds">4.9</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">5.0</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">3.9</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">15.2</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">15.9</span> (<span title="iterations">37</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QADLITTL.SIF" title="97 vars, 15 eqs, 56 ineqs">QADLITTL</a></td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">3.1</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">5.4</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">2.8</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">25</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QAFIRO.SIF" title="32 vars, 8 eqs, 27 ineqs">QAFIRO</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBANDM.SIF" title="472 vars, 305 eqs, 305 ineqs">QBANDM</a></td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBEACONF.SIF" title="262 vars, 140 eqs, 173 ineqs">QBEACONF</a></td>
 *   <td><span title="runtime in milliseconds">6.2</span> (<span title="iterations">84</span>)</td>
 *   <td><span title="runtime in milliseconds">7.6</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">11.0</span> (<span title="iterations">63</span>)</td>
 *   <td><span title="runtime in milliseconds">17.8</span> (<span title="iterations">93</span>)</td>
 *   <td><span title="runtime in milliseconds">10.0</span> (<span title="iterations">72</span>)</td>
 *   <td><span title="runtime in milliseconds">8.8</span> (<span title="iterations">56</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBORE3D.SIF" title="315 vars, 214 eqs, 233 ineqs">QBORE3D</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBRANDY.SIF" title="249 vars, 166 eqs, 220 ineqs">QBRANDY</a></td>
 *   <td><span title="runtime in milliseconds">322.7</span> (<span title="iterations">1214</span>)</td>
 *   <td><span title="runtime in milliseconds">29.4</span> (<span title="iterations">76</span>)</td>
 *   <td><span title="runtime in milliseconds">34.2</span> (<span title="iterations">78</span>)</td>
 *   <td><span title="runtime in milliseconds">47.6</span> (<span title="iterations">92</span>)</td>
 *   <td><span title="runtime in milliseconds">128.5</span> (<span title="iterations">246</span>)</td>
 *   <td><span title="runtime in milliseconds">118.1</span> (<span title="iterations">214</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QCAPRI.SIF" title="353 vars, 142 eqs, 271 ineqs">QCAPRI</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QE226.SIF" title="282 vars, 33 eqs, 223 ineqs">QE226</a></td>
 *   <td><span title="runtime in milliseconds">833.9</span> (<span title="iterations">2122</span>)</td>
 *   <td><span title="runtime in milliseconds">876.5</span> (<span title="iterations">994</span>)</td>
 *   <td><span title="runtime in milliseconds">964.6</span> (<span title="iterations">954</span>)</td>
 *   <td><span title="runtime in milliseconds">760.1</span> (<span title="iterations">834</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QETAMACR.SIF" title="688 vars, 272 eqs, 400 ineqs">QETAMACR</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QFFFFF80.SIF" title="854 vars, 350 eqs, 524 ineqs">QFFFFF80</a></td>
 *   <td><span title="runtime in milliseconds">5068.8</span> (<span title="iterations">2522</span>)</td>
 *   <td><span title="runtime in milliseconds">2475.8</span> (<span title="iterations">693</span>)</td>
 *   <td><span title="runtime in milliseconds">2785.9</span> (<span title="iterations">770</span>)</td>
 *   <td><span title="runtime in milliseconds">2964.4</span> (<span title="iterations">802</span>)</td>
 *   <td><span title="runtime in milliseconds">17990.3</span> (<span title="iterations">4004</span>)</td>
 *   <td><span title="runtime in milliseconds">8670.3</span> (<span title="iterations">2100</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGFRDXPN.SIF" title="1092 vars, 548 eqs, 616 ineqs">QGFRDXPN</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW15.SIF" title="645 vars, 300 eqs, 300 ineqs">QGROW15</a></td>
 *   <td><span title="runtime in milliseconds">224.5</span> (<span title="iterations">906</span>)</td>
 *   <td><span title="runtime in milliseconds">364.9</span> (<span title="iterations">637</span>)</td>
 *   <td><span title="runtime in milliseconds">441.4</span> (<span title="iterations">676</span>)</td>
 *   <td><span title="runtime in milliseconds">626.8</span> (<span title="iterations">746</span>)</td>
 *   <td><span title="runtime in milliseconds">331.7</span> (<span title="iterations">495</span>)</td>
 *   <td><span title="runtime in milliseconds">324.7</span> (<span title="iterations">407</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW22.SIF" title="946 vars, 440 eqs, 440 ineqs">QGROW22</a></td>
 *   <td><span title="runtime in milliseconds">481.7</span> (<span title="iterations">1352</span>)</td>
 *   <td><span title="runtime in milliseconds">802.4</span> (<span title="iterations">828</span>)</td>
 *   <td><span title="runtime in milliseconds">902.9</span> (<span title="iterations">868</span>)</td>
 *   <td><span title="runtime in milliseconds">1079.2</span> (<span title="iterations">877</span>)</td>
 *   <td><span title="runtime in milliseconds">3150.2</span> (<span title="iterations">3081</span>)</td>
 *   <td><span title="runtime in milliseconds">719.7</span> (<span title="iterations">597</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW7.SIF" title="301 vars, 140 eqs, 140 ineqs">QGROW7</a></td>
 *   <td><span title="runtime in milliseconds">243.4</span> (<span title="iterations">1718</span>)</td>
 *   <td><span title="runtime in milliseconds">331.4</span> (<span title="iterations">1007</span>)</td>
 *   <td><span title="runtime in milliseconds">364.3</span> (<span title="iterations">1023</span>)</td>
 *   <td><span title="runtime in milliseconds">522.3</span> (<span title="iterations">1098</span>)</td>
 *   <td><span title="runtime in milliseconds">135.7</span> (<span title="iterations">436</span>)</td>
 *   <td><span title="runtime in milliseconds">229.6</span> (<span title="iterations">572</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QISRAEL.SIF" title="142 vars, 174 ineqs">QISRAEL</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCBLEND.SIF" title="83 vars, 43 eqs, 74 ineqs">QPCBLEND</a></td>
 *   <td><span title="runtime in milliseconds">108.4</span> (<span title="iterations">1745</span>)</td>
 *   <td><span title="runtime in milliseconds">59.8</span> (<span title="iterations">346</span>)</td>
 *   <td><span title="runtime in milliseconds">67.6</span> (<span title="iterations">365</span>)</td>
 *   <td><span title="runtime in milliseconds">80.4</span> (<span title="iterations">342</span>)</td>
 *   <td><span title="runtime in milliseconds">36.4</span> (<span title="iterations">269</span>)</td>
 *   <td><span title="runtime in milliseconds">36.9</span> (<span title="iterations">229</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QPCSTAIR</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">448.1</span> (<span title="iterations">1129</span>)</td>
 *   <td><span title="runtime in milliseconds">654.9</span> (<span title="iterations">1421</span>)</td>
 *   <td><span title="runtime in milliseconds">716.5</span> (<span title="iterations">1040</span>)</td>
 *   <td><span title="runtime in milliseconds">241.3</span> (<span title="iterations">468</span>)</td>
 *   <td><span title="runtime in milliseconds">317.1</span> (<span title="iterations">523</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPILOTNO.SIF" title="2172 vars, 701 eqs, 975 ineqs">QPILOTNO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPTEST.SIF" title="2 vars, 2 ineqs">QPTEST</a></td>
 *   <td><span title="runtime in milliseconds">4.2</span> (<span title="iterations">199</span>)</td>
 *   <td><span title="runtime in milliseconds">2.1</span> (<span title="iterations">48</span>)</td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">41</span>)</td>
 *   <td><span title="runtime in milliseconds">14.4</span> (<span title="iterations">113</span>)</td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">33</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QRECIPE.SIF" title="180 vars, 67 eqs, 91 ineqs">QRECIPE</a></td>
 *   <td><span title="runtime in milliseconds">35.5</span> (<span title="iterations">714</span>)</td>
 *   <td><span title="runtime in milliseconds">77.7</span> (<span title="iterations">505</span>)</td>
 *   <td><span title="runtime in milliseconds">105.4</span> (<span title="iterations">472</span>)</td>
 *   <td><span title="runtime in milliseconds">130.4</span> (<span title="iterations">538</span>)</td>
 *   <td><span title="runtime in milliseconds">25.5</span> (<span title="iterations">201</span>)</td>
 *   <td><span title="runtime in milliseconds">26.1</span> (<span title="iterations">184</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSC205.SIF" title="203 vars, 91 eqs, 205 ineqs">QSC205</a></td>
 *   <td><span title="runtime in milliseconds">12.1</span> (<span title="iterations">262</span>)</td>
 *   <td><span title="runtime in milliseconds">18.4</span> (<span title="iterations">135</span>)</td>
 *   <td><span title="runtime in milliseconds">13.1</span> (<span title="iterations">93</span>)</td>
 *   <td><span title="runtime in milliseconds">17.3</span> (<span title="iterations">91</span>)</td>
 *   <td><span title="runtime in milliseconds">20.3</span> (<span title="iterations">177</span>)</td>
 *   <td><span title="runtime in milliseconds">28.0</span> (<span title="iterations">206</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR25.SIF" title="500 vars, 300 eqs, 471 ineqs">QSCAGR25</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">2.1</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR7.SIF" title="140 vars, 84 eqs, 129 ineqs">QSCAGR7</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM1.SIF" title="457 vars, 187 eqs, 330 ineqs">QSCFXM1</a></td>
 *   <td><span title="runtime in milliseconds">14.7</span> (<span title="iterations">65</span>)</td>
 *   <td><span title="runtime in milliseconds">23.9</span> (<span title="iterations">57</span>)</td>
 *   <td><span title="runtime in milliseconds">20.9</span> (<span title="iterations">51</span>)</td>
 *   <td><span title="runtime in milliseconds">24.2</span> (<span title="iterations">55</span>)</td>
 *   <td><span title="runtime in milliseconds">36.2</span> (<span title="iterations">84</span>)</td>
 *   <td><span title="runtime in milliseconds">37.4</span> (<span title="iterations">64</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM2.SIF" title="914 vars, 374 eqs, 660 ineqs">QSCFXM2</a></td>
 *   <td><span title="runtime in milliseconds">31.7</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">58.4</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">54.0</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">46.7</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">67.1</span> (<span title="iterations">73</span>)</td>
 *   <td><span title="runtime in milliseconds">150.0</span> (<span title="iterations">141</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM3.SIF" title="1371 vars, 561 eqs, 990 ineqs">QSCFXM3</a></td>
 *   <td><span title="runtime in milliseconds">36.5</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">57.5</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">86.5</span> (<span title="iterations">67</span>)</td>
 *   <td><span title="runtime in milliseconds">114.8</span> (<span title="iterations">62</span>)</td>
 *   <td><span title="runtime in milliseconds">54.8</span> (<span title="iterations">37</span>)</td>
 *   <td><span title="runtime in milliseconds">49.6</span> (<span title="iterations">37</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCORPIO.SIF" title="358 vars, 280 eqs, 388 ineqs">QSCORPIO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">1446.6</span> (<span title="iterations">3820</span>)</td>
 *   <td><span title="runtime in milliseconds">483.0</span> (<span title="iterations">1209</span>)</td>
 *   <td><span title="runtime in milliseconds">365.0</span> (<span title="iterations">1017</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCRS8.SIF" title="1169 vars, 384 eqs, 490 ineqs">QSCRS8</a></td>
 *   <td><span title="runtime in milliseconds">1.5</span> (<span title="iterations">23</span>)</td>
 *   <td><span title="runtime in milliseconds">7.2</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">17.5</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">10.2</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">5.8</span> (<span title="iterations">23</span>)</td>
 *   <td><span title="runtime in milliseconds">4.2</span> (<span title="iterations">23</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD1.SIF" title="760 vars, 77 eqs, 77 ineqs">QSCSD1</a></td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">1.0</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">3.9</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">2.9</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">2.0</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">1.8</span> (<span title="iterations">14</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD6.SIF" title="1350 vars, 147 eqs, 147 ineqs">QSCSD6</a></td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">3.1</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">2.4</span> (<span title="iterations">13</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD8.SIF" title="2750 vars, 397 eqs, 397 ineqs">QSCSD8</a></td>
 *   <td><span title="runtime in milliseconds">3.1</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">3.3</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">3.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">3.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">5.1</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">4.9</span> (<span title="iterations">11</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP1.SIF" title="480 vars, 120 eqs, 300 ineqs">QSCTAP1</a></td>
 *   <td><span title="runtime in milliseconds">15.8</span> (<span title="iterations">160</span>)</td>
 *   <td><span title="runtime in milliseconds">5.8</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">5.3</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">13.5</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">18.9</span> (<span title="iterations">70</span>)</td>
 *   <td><span title="runtime in milliseconds">18.0</span> (<span title="iterations">60</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP2.SIF" title="1880 vars, 470 eqs, 1090 ineqs">QSCTAP2</a></td>
 *   <td><span title="runtime in milliseconds">35.9</span> (<span title="iterations">60</span>)</td>
 *   <td><span title="runtime in milliseconds">26.6</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">26.4</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">36.5</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">39.7</span> (<span title="iterations">30</span>)</td>
 *   <td><span title="runtime in milliseconds">36.5</span> (<span title="iterations">30</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP3.SIF" title="2480 vars, 620 eqs, 1480 ineqs">QSCTAP3</a></td>
 *   <td><span title="runtime in milliseconds">74.9</span> (<span title="iterations">149</span>)</td>
 *   <td><span title="runtime in milliseconds">33.7</span> (<span title="iterations">35</span>)</td>
 *   <td><span title="runtime in milliseconds">32.0</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">33.9</span> (<span title="iterations">27</span>)</td>
 *   <td><span title="runtime in milliseconds">47.7</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">50.8</span> (<span title="iterations">33</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSEBA.SIF" title="1028 vars, 507 eqs, 515 ineqs">QSEBA</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHARE1B.SIF" title="225 vars, 89 eqs, 117 ineqs">QSHARE1B</a></td>
 *   <td><span title="runtime in milliseconds">301.6</span> (<span title="iterations">2626</span>)</td>
 *   <td><span title="runtime in milliseconds">136.9</span> (<span title="iterations">541</span>)</td>
 *   <td><span title="runtime in milliseconds">97.8</span> (<span title="iterations">492</span>)</td>
 *   <td><span title="runtime in milliseconds">114.8</span> (<span title="iterations">456</span>)</td>
 *   <td><span title="runtime in milliseconds">106.0</span> (<span title="iterations">445</span>)</td>
 *   <td><span title="runtime in milliseconds">128.7</span> (<span title="iterations">461</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHELL.SIF" title="1775 vars, 534 eqs, 536 ineqs">QSHELL</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">82613.2</span> (<span title="iterations">4266</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04L.SIF" title="2118 vars, 354 eqs, 402 ineqs">QSHIP04L</a></td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">6.6</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">6.6</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">9.2</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">11</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04S.SIF" title="1458 vars, 354 eqs, 402 ineqs">QSHIP04S</a></td>
 *   <td><span title="runtime in milliseconds">1.3</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">4.2</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">6.3</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">3.2</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">9</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08L.SIF" title="4283 vars, 698 eqs, 778 ineqs">QSHIP08L</a></td>
 *   <td><span title="runtime in milliseconds">54.2</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">46.9</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">43.5</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">41.0</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">84.2</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">79.7</span> (<span title="iterations">18</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08S.SIF" title="2387 vars, 698 eqs, 778 ineqs">QSHIP08S</a></td>
 *   <td><span title="runtime in milliseconds">20.6</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">20.0</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">21.9</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">21.1</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">32.3</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">32.0</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12L.SIF" title="5427 vars, 1045 eqs, 1151 ineqs">QSHIP12L</a></td>
 *   <td><span title="runtime in milliseconds">139.1</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">154.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">139.1</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">144.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">293.7</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">273.7</span> (<span title="iterations">16</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12S.SIF" title="2763 vars, 1045 eqs, 1151 ineqs">QSHIP12S</a></td>
 *   <td><span title="runtime in milliseconds">36.3</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">41.9</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">41.8</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">43.2</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">69.7</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">66.7</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSIERRA.SIF" title="2036 vars, 528 eqs, 1227 ineqs">QSIERRA</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QSTAIR</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTANDAT.SIF" title="1075 vars, 160 eqs, 359 ineqs">QSTANDAT</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">7934.6</span> (<span title="iterations">4961</span>)</td>
 *   <td><span title="runtime in milliseconds">8210.5</span> (<span title="iterations">4837</span>)</td>
 *   <td><span title="runtime in milliseconds">9302.2</span> (<span title="iterations">4756</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/S268.SIF" title="5 vars, 5 ineqs">S268</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">15</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">18</span>)</td>
 *   <td><span title="runtime in milliseconds">0.8</span> (<span title="iterations">18</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP1.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP1</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">10795.5</span> (<span title="iterations">2889</span>)</td>
 *   <td><span title="runtime in milliseconds">18272.8</span> (<span title="iterations">4138</span>)</td>
 *   <td><span title="runtime in milliseconds">22682.7</span> (<span title="iterations">3936</span>)</td>
 *   <td><span title="runtime in milliseconds">3305.6</span> (<span title="iterations">725</span>)</td>
 *   <td><span title="runtime in milliseconds">5207.9</span> (<span title="iterations">910</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP2.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP2</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">6776.4</span> (<span title="iterations">1214</span>)</td>
 *   <td><span title="runtime in milliseconds">5915.1</span> (<span title="iterations">1026</span>)</td>
 *   <td><span title="runtime in milliseconds">9549.1</span> (<span title="iterations">1385</span>)</td>
 *   <td><span title="runtime in milliseconds">3735.1</span> (<span title="iterations">531</span>)</td>
 *   <td><span title="runtime in milliseconds">4642.8</span> (<span title="iterations">579</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/TAME.SIF" title="2 vars, 1 eqs, 1 ineqs">TAME</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/YAO.SIF" title="2002 vars, 2000 ineqs">YAO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  </table>
 * </div>
 * 
 * 
 * 
 * \subsection mm-with-qr Using QR in AA
 * [[RAW DATA (with QR)]](data/maros-meszaros-02.txt)
 * 
 * <div>
 *  <table>
 *  <tr>
 *   <th>PROBLEM</th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:3</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:5</span></th>
 *   <th><span title="(k0,k1,k2)=(1,1,1), ls=10">Anderson, mem:10</span></th>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2D.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2D</a></td>
 *   <td><span title="runtime in milliseconds">7130.7</span> (<span title="iterations">249</span>)</td>
 *   <td><span title="runtime in milliseconds">9320.4</span> (<span title="iterations">277</span>)</td>
 *   <td><span title="runtime in milliseconds">53051.6</span> (<span title="iterations">1070</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DC.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DC</a></td>
 *   <td><span title="runtime in milliseconds">102062.9</span> (<span title="iterations">2232</span>)</td>
 *   <td><span title="runtime in milliseconds">4169.2</span> (<span title="iterations">153</span>)</td>
 *   <td><span title="runtime in milliseconds">9992.7</span> (<span title="iterations">281</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG2DCQP.SIF" title="20200 vars, 10000 eqs, 10000 ineqs">AUG2DCQP</a></td>
 *   <td><span title="runtime in milliseconds">292.9</span> (<span title="iterations">32</span>)</td>
 *   <td><span title="runtime in milliseconds">386.6</span> (<span title="iterations">31</span>)</td>
 *   <td><span title="runtime in milliseconds">507.8</span> (<span title="iterations">28</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3D.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3D</a></td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">0</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DC.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DC</a></td>
 *   <td><span title="runtime in milliseconds">43.4</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">22.6</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">57.5</span> (<span title="iterations">37</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DCQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DCQP</a></td>
 *   <td><span title="runtime in milliseconds">1357.1</span> (<span title="iterations">698</span>)</td>
 *   <td><span title="runtime in milliseconds">889.6</span> (<span title="iterations">426</span>)</td>
 *   <td><span title="runtime in milliseconds">997.3</span> (<span title="iterations">316</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/AUG3DQP.SIF" title="3873 vars, 1000 eqs, 1000 ineqs">AUG3DQP</a></td>
 *   <td><span title="runtime in milliseconds">893.5</span> (<span title="iterations">242</span>)</td>
 *   <td><span title="runtime in milliseconds">1926.1</span> (<span title="iterations">469</span>)</td>
 *   <td><span title="runtime in milliseconds">627.9</span> (<span title="iterations">147</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-050.SIF" title="2597 vars, 2401 eqs, 2401 ineqs">CONT-050</a></td>
 *   <td><span title="runtime in milliseconds">1496.3</span> (<span title="iterations">770</span>)</td>
 *   <td><span title="runtime in milliseconds">1906.8</span> (<span title="iterations">783</span>)</td>
 *   <td><span title="runtime in milliseconds">2656.2</span> (<span title="iterations">760</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/CONT-100.SIF" title="10197 vars, 9801 eqs, 9801 ineqs">CONT-100</a></td>
 *   <td><span title="runtime in milliseconds">8263.9</span> (<span title="iterations">944</span>)</td>
 *   <td><span title="runtime in milliseconds">10729.1</span> (<span title="iterations">951</span>)</td>
 *   <td><span title="runtime in milliseconds">13617.9</span> (<span title="iterations">765</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DPKLO1.SIF" title="133 vars, 77 eqs, 77 ineqs">DPKLO1</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL1.SIF" title="85 vars, 1 eqs, 1 ineqs">DUAL1</a></td>
 *   <td><span title="runtime in milliseconds">8.1</span> (<span title="iterations">42</span>)</td>
 *   <td><span title="runtime in milliseconds">11.0</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">12.6</span> (<span title="iterations">53</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL2.SIF" title="96 vars, 1 eqs, 1 ineqs">DUAL2</a></td>
 *   <td><span title="runtime in milliseconds">13.1</span> (<span title="iterations">59</span>)</td>
 *   <td><span title="runtime in milliseconds">14.1</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">18.4</span> (<span title="iterations">58</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL3.SIF" title="111 vars, 1 eqs, 1 ineqs">DUAL3</a></td>
 *   <td><span title="runtime in milliseconds">12.4</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">15.6</span> (<span title="iterations">57</span>)</td>
 *   <td><span title="runtime in milliseconds">20.9</span> (<span title="iterations">60</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUAL4.SIF" title="75 vars, 1 eqs, 1 ineqs">DUAL4</a></td>
 *   <td><span title="runtime in milliseconds">4.4</span> (<span title="iterations">35</span>)</td>
 *   <td><span title="runtime in milliseconds">8.1</span> (<span title="iterations">33</span>)</td>
 *   <td><span title="runtime in milliseconds">8.0</span> (<span title="iterations">44</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC1.SIF" title="9 vars, 1 eqs, 215 ineqs">DUALC1</a></td>
 *   <td><span title="runtime in milliseconds">24.2</span> (<span title="iterations">178</span>)</td>
 *   <td><span title="runtime in milliseconds">16.4</span> (<span title="iterations">103</span>)</td>
 *   <td><span title="runtime in milliseconds">19.8</span> (<span title="iterations">123</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC2.SIF" title="7 vars, 1 eqs, 229 ineqs">DUALC2</a></td>
 *   <td><span title="runtime in milliseconds">21.1</span> (<span title="iterations">169</span>)</td>
 *   <td><span title="runtime in milliseconds">21.6</span> (<span title="iterations">157</span>)</td>
 *   <td><span title="runtime in milliseconds">16.6</span> (<span title="iterations">108</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC5.SIF" title="8 vars, 1 eqs, 278 ineqs">DUALC5</a></td>
 *   <td><span title="runtime in milliseconds">17.8</span> (<span title="iterations">135</span>)</td>
 *   <td><span title="runtime in milliseconds">13.6</span> (<span title="iterations">82</span>)</td>
 *   <td><span title="runtime in milliseconds">13.9</span> (<span title="iterations">91</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/DUALC8.SIF" title="8 vars, 1 eqs, 503 ineqs">DUALC8</a></td>
 *   <td><span title="runtime in milliseconds">36.0</span> (<span title="iterations">171</span>)</td>
 *   <td><span title="runtime in milliseconds">57.7</span> (<span title="iterations">169</span>)</td>
 *   <td><span title="runtime in milliseconds">27.7</span> (<span title="iterations">95</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GENHS28.SIF" title="10 vars, 8 eqs, 8 ineqs">GENHS28</a></td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/GOULDQP3.SIF" title="699 vars, 349 eqs, 349 ineqs">GOULDQP3</a></td>
 *   <td><span title="runtime in milliseconds">173.0</span> (<span title="iterations">317</span>)</td>
 *   <td><span title="runtime in milliseconds">212.8</span> (<span title="iterations">340</span>)</td>
 *   <td><span title="runtime in milliseconds">246.9</span> (<span title="iterations">293</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS118.SIF" title="15 vars, 17 ineqs">HS118</a></td>
 *   <td><span title="runtime in milliseconds">2.8</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">3.5</span> (<span title="iterations">46</span>)</td>
 *   <td><span title="runtime in milliseconds">3.2</span> (<span title="iterations">45</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS21.SIF" title="2 vars, 1 ineqs">HS21</a></td>
 *   <td><span title="runtime in milliseconds">2.7</span> (<span title="iterations">75</span>)</td>
 *   <td><span title="runtime in milliseconds">81.9</span> (<span title="iterations">927</span>)</td>
 *   <td><span title="runtime in milliseconds">107.1</span> (<span title="iterations">743</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS268.SIF" title="5 vars, 5 ineqs">HS268</a></td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">15</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35.SIF" title="3 vars, 1 ineqs">HS35</a></td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">15</span>)</td>
 *   <td><span title="runtime in milliseconds">1.1</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS35MOD.SIF" title="3 vars, 1 ineqs">HS35MOD</a></td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">17</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">14</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS51.SIF" title="5 vars, 3 eqs, 3 ineqs">HS51</a></td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS52.SIF" title="5 vars, 3 eqs, 3 ineqs">HS52</a></td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">8</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS53.SIF" title="5 vars, 3 eqs, 3 ineqs">HS53</a></td>
 *   <td><span title="runtime in milliseconds">2.5</span> (<span title="iterations">69</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">1.3</span> (<span title="iterations">22</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HS76.SIF" title="4 vars, 3 ineqs">HS76</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">13</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUES-MOD.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUES-MOD</a></td>
 *   <td><span title="runtime in milliseconds">10711.3</span> (<span title="iterations">2475</span>)</td>
 *   <td><span title="runtime in milliseconds">16060.7</span> (<span title="iterations">2897</span>)</td>
 *   <td><span title="runtime in milliseconds">16644.0</span> (<span title="iterations">2056</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/HUESTIS.SIF" title="10000 vars, 2 eqs, 2 ineqs">HUESTIS</a></td>
 *   <td><span title="runtime in milliseconds">56.1</span> (<span title="iterations">14</span>)</td>
 *   <td><span title="runtime in milliseconds">32.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">111.3</span> (<span title="iterations">19</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/KSIP.SIF" title="20 vars, 1001 ineqs">KSIP</a></td>
 *   <td><span title="runtime in milliseconds">122.1</span> (<span title="iterations">108</span>)</td>
 *   <td><span title="runtime in milliseconds">97.2</span> (<span title="iterations">86</span>)</td>
 *   <td><span title="runtime in milliseconds">118.9</span> (<span title="iterations">88</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LASER.SIF" title="1002 vars, 1000 ineqs">LASER</a></td>
 *   <td><span title="runtime in milliseconds">2153.0</span> (<span title="iterations">2074</span>)</td>
 *   <td><span title="runtime in milliseconds">2397.3</span> (<span title="iterations">2177</span>)</td>
 *   <td><span title="runtime in milliseconds">3188.0</span> (<span title="iterations">2279</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET1.SIF" title="10002 vars, 10000 ineqs">LISWET1</a></td>
 *   <td><span title="runtime in milliseconds">8213.1</span> (<span title="iterations">1437</span>)</td>
 *   <td><span title="runtime in milliseconds">8971.3</span> (<span title="iterations">1343</span>)</td>
 *   <td><span title="runtime in milliseconds">7722.1</span> (<span title="iterations">861</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET10.SIF" title="10002 vars, 10000 ineqs">LISWET10</a></td>
 *   <td><span title="runtime in milliseconds">8615.2</span> (<span title="iterations">1500</span>)</td>
 *   <td><span title="runtime in milliseconds">9416.9</span> (<span title="iterations">1380</span>)</td>
 *   <td><span title="runtime in milliseconds">7933.1</span> (<span title="iterations">880</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET11.SIF" title="10002 vars, 10000 ineqs">LISWET11</a></td>
 *   <td><span title="runtime in milliseconds">8504.8</span> (<span title="iterations">1490</span>)</td>
 *   <td><span title="runtime in milliseconds">9315.9</span> (<span title="iterations">1398</span>)</td>
 *   <td><span title="runtime in milliseconds">8212.1</span> (<span title="iterations">910</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET12.SIF" title="10002 vars, 10000 ineqs">LISWET12</a></td>
 *   <td><span title="runtime in milliseconds">8706.3</span> (<span title="iterations">1477</span>)</td>
 *   <td><span title="runtime in milliseconds">10054.2</span> (<span title="iterations">1406</span>)</td>
 *   <td><span title="runtime in milliseconds">8897.6</span> (<span title="iterations">912</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET2.SIF" title="10002 vars, 10000 ineqs">LISWET2</a></td>
 *   <td><span title="runtime in milliseconds">6360.8</span> (<span title="iterations">1182</span>)</td>
 *   <td><span title="runtime in milliseconds">6469.2</span> (<span title="iterations">1036</span>)</td>
 *   <td><span title="runtime in milliseconds">5694.7</span> (<span title="iterations">698</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET3.SIF" title="10002 vars, 10000 ineqs">LISWET3</a></td>
 *   <td><span title="runtime in milliseconds">4557.5</span> (<span title="iterations">838</span>)</td>
 *   <td><span title="runtime in milliseconds">4477.8</span> (<span title="iterations">748</span>)</td>
 *   <td><span title="runtime in milliseconds">4818.6</span> (<span title="iterations">538</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET4.SIF" title="10002 vars, 10000 ineqs">LISWET4</a></td>
 *   <td><span title="runtime in milliseconds">3774.9</span> (<span title="iterations">684</span>)</td>
 *   <td><span title="runtime in milliseconds">3831.1</span> (<span title="iterations">611</span>)</td>
 *   <td><span title="runtime in milliseconds">3484.5</span> (<span title="iterations">443</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET5.SIF" title="10002 vars, 10000 ineqs">LISWET5</a></td>
 *   <td><span title="runtime in milliseconds">25833.1</span> (<span title="iterations">4122</span>)</td>
 *   <td><span title="runtime in milliseconds">25444.9</span> (<span title="iterations">3524</span>)</td>
 *   <td><span title="runtime in milliseconds">24655.4</span> (<span title="iterations">2620</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET6.SIF" title="10002 vars, 10000 ineqs">LISWET6</a></td>
 *   <td><span title="runtime in milliseconds">8021.9</span> (<span title="iterations">1348</span>)</td>
 *   <td><span title="runtime in milliseconds">8314.7</span> (<span title="iterations">1268</span>)</td>
 *   <td><span title="runtime in milliseconds">7434.7</span> (<span title="iterations">840</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET7.SIF" title="10002 vars, 10000 ineqs">LISWET7</a></td>
 *   <td><span title="runtime in milliseconds">8367.7</span> (<span title="iterations">1468</span>)</td>
 *   <td><span title="runtime in milliseconds">9505.1</span> (<span title="iterations">1382</span>)</td>
 *   <td><span title="runtime in milliseconds">8416.6</span> (<span title="iterations">902</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET8.SIF" title="10002 vars, 10000 ineqs">LISWET8</a></td>
 *   <td><span title="runtime in milliseconds">8961.3</span> (<span title="iterations">1536</span>)</td>
 *   <td><span title="runtime in milliseconds">9732.5</span> (<span title="iterations">1386</span>)</td>
 *   <td><span title="runtime in milliseconds">8041.5</span> (<span title="iterations">892</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/LISWET9.SIF" title="10002 vars, 10000 ineqs">LISWET9</a></td>
 *   <td><span title="runtime in milliseconds">8640.5</span> (<span title="iterations">1497</span>)</td>
 *   <td><span title="runtime in milliseconds">9406.3</span> (<span title="iterations">1390</span>)</td>
 *   <td><span title="runtime in milliseconds">8210.1</span> (<span title="iterations">909</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP1.SIF" title="2500 vars, 700 ineqs">MOSARQP1</a></td>
 *   <td><span title="runtime in milliseconds">983.8</span> (<span title="iterations">421</span>)</td>
 *   <td><span title="runtime in milliseconds">967.0</span> (<span title="iterations">412</span>)</td>
 *   <td><span title="runtime in milliseconds">1280.9</span> (<span title="iterations">398</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/MOSARQP2.SIF" title="900 vars, 600 ineqs">MOSARQP2</a></td>
 *   <td><span title="runtime in milliseconds">175.2</span> (<span title="iterations">270</span>)</td>
 *   <td><span title="runtime in milliseconds">183.1</span> (<span title="iterations">227</span>)</td>
 *   <td><span title="runtime in milliseconds">203.3</span> (<span title="iterations">186</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/POWELL20.SIF" title="10000 vars, 10000 ineqs">POWELL20</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL1.SIF" title="325 vars, 85 ineqs">PRIMAL1</a></td>
 *   <td><span title="runtime in milliseconds">18.3</span> (<span title="iterations">44</span>)</td>
 *   <td><span title="runtime in milliseconds">19.3</span> (<span title="iterations">41</span>)</td>
 *   <td><span title="runtime in milliseconds">18.6</span> (<span title="iterations">38</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL2.SIF" title="649 vars, 96 ineqs">PRIMAL2</a></td>
 *   <td><span title="runtime in milliseconds">9.1</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">11.3</span> (<span title="iterations">20</span>)</td>
 *   <td><span title="runtime in milliseconds">11.9</span> (<span title="iterations">19</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL3.SIF" title="745 vars, 111 ineqs">PRIMAL3</a></td>
 *   <td><span title="runtime in milliseconds">21.5</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">21.1</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">19.3</span> (<span title="iterations">20</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMAL4.SIF" title="1489 vars, 75 ineqs">PRIMAL4</a></td>
 *   <td><span title="runtime in milliseconds">21.8</span> (<span title="iterations">30</span>)</td>
 *   <td><span title="runtime in milliseconds">19.7</span> (<span title="iterations">24</span>)</td>
 *   <td><span title="runtime in milliseconds">18.2</span> (<span title="iterations">20</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC1.SIF" title="230 vars, 9 ineqs">PRIMALC1</a></td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">9</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">8</span>)</td>
 *   <td><span title="runtime in milliseconds">4.1</span> (<span title="iterations">13</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC5.SIF" title="287 vars, 8 ineqs">PRIMALC5</a></td>
 *   <td><span title="runtime in milliseconds">6.9</span> (<span title="iterations">40</span>)</td>
 *   <td><span title="runtime in milliseconds">15.8</span> (<span title="iterations">64</span>)</td>
 *   <td><span title="runtime in milliseconds">33.4</span> (<span title="iterations">105</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/PRIMALC8.SIF" title="520 vars, 8 ineqs">PRIMALC8</a></td>
 *   <td><span title="runtime in milliseconds">3.7</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">5.1</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">3.8</span> (<span title="iterations">11</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QADLITTL.SIF" title="97 vars, 15 eqs, 56 ineqs">QADLITTL</a></td>
 *   <td><span title="runtime in milliseconds">1.2</span> (<span title="iterations">19</span>)</td>
 *   <td><span title="runtime in milliseconds">2.3</span> (<span title="iterations">16</span>)</td>
 *   <td><span title="runtime in milliseconds">2.8</span> (<span title="iterations">17</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QAFIRO.SIF" title="32 vars, 8 eqs, 27 ineqs">QAFIRO</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBANDM.SIF" title="472 vars, 305 eqs, 305 ineqs">QBANDM</a></td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">6</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBEACONF.SIF" title="262 vars, 140 eqs, 173 ineqs">QBEACONF</a></td>
 *   <td><span title="runtime in milliseconds">5.2</span> (<span title="iterations">54</span>)</td>
 *   <td><span title="runtime in milliseconds">9.1</span> (<span title="iterations">63</span>)</td>
 *   <td><span title="runtime in milliseconds">13.2</span> (<span title="iterations">93</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBORE3D.SIF" title="315 vars, 214 eqs, 233 ineqs">QBORE3D</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QBRANDY.SIF" title="249 vars, 166 eqs, 220 ineqs">QBRANDY</a></td>
 *   <td><span title="runtime in milliseconds">25.8</span> (<span title="iterations">77</span>)</td>
 *   <td><span title="runtime in milliseconds">44.2</span> (<span title="iterations">101</span>)</td>
 *   <td><span title="runtime in milliseconds">35.9</span> (<span title="iterations">85</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QCAPRI.SIF" title="353 vars, 142 eqs, 271 ineqs">QCAPRI</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QE226.SIF" title="282 vars, 33 eqs, 223 ineqs">QE226</a></td>
 *   <td><span title="runtime in milliseconds">829.7</span> (<span title="iterations">1023</span>)</td>
 *   <td><span title="runtime in milliseconds">802.6</span> (<span title="iterations">1021</span>)</td>
 *   <td><span title="runtime in milliseconds">472.7</span> (<span title="iterations">624</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QETAMACR.SIF" title="688 vars, 272 eqs, 400 ineqs">QETAMACR</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QFFFFF80.SIF" title="854 vars, 350 eqs, 524 ineqs">QFFFFF80</a></td>
 *   <td><span title="runtime in milliseconds">3969.0</span> (<span title="iterations">1100</span>)</td>
 *   <td><span title="runtime in milliseconds">2351.2</span> (<span title="iterations">724</span>)</td>
 *   <td><span title="runtime in milliseconds">2784.0</span> (<span title="iterations">840</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGFRDXPN.SIF" title="1092 vars, 548 eqs, 616 ineqs">QGFRDXPN</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW15.SIF" title="645 vars, 300 eqs, 300 ineqs">QGROW15</a></td>
 *   <td><span title="runtime in milliseconds">341.4</span> (<span title="iterations">633</span>)</td>
 *   <td><span title="runtime in milliseconds">396.2</span> (<span title="iterations">680</span>)</td>
 *   <td><span title="runtime in milliseconds">621.4</span> (<span title="iterations">748</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW22.SIF" title="946 vars, 440 eqs, 440 ineqs">QGROW22</a></td>
 *   <td><span title="runtime in milliseconds">586.0</span> (<span title="iterations">783</span>)</td>
 *   <td><span title="runtime in milliseconds">717.8</span> (<span title="iterations">809</span>)</td>
 *   <td><span title="runtime in milliseconds">1039.7</span> (<span title="iterations">855</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QGROW7.SIF" title="301 vars, 140 eqs, 140 ineqs">QGROW7</a></td>
 *   <td><span title="runtime in milliseconds">310.4</span> (<span title="iterations">1001</span>)</td>
 *   <td><span title="runtime in milliseconds">381.2</span> (<span title="iterations">1078</span>)</td>
 *   <td><span title="runtime in milliseconds">1097.2</span> (<span title="iterations">2283</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QISRAEL.SIF" title="142 vars, 174 ineqs">QISRAEL</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCBLEND.SIF" title="83 vars, 43 eqs, 74 ineqs">QPCBLEND</a></td>
 *   <td><span title="runtime in milliseconds">33.1</span> (<span title="iterations">333</span>)</td>
 *   <td><span title="runtime in milliseconds">58.0</span> (<span title="iterations">439</span>)</td>
 *   <td><span title="runtime in milliseconds">47.7</span> (<span title="iterations">357</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPCSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QPCSTAIR</a></td>
 *   <td><span title="runtime in milliseconds">605.9</span> (<span title="iterations">1591</span>)</td>
 *   <td><span title="runtime in milliseconds">543.7</span> (<span title="iterations">1385</span>)</td>
 *   <td><span title="runtime in milliseconds">724.7</span> (<span title="iterations">1513</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPILOTNO.SIF" title="2172 vars, 701 eqs, 975 ineqs">QPILOTNO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QPTEST.SIF" title="2 vars, 2 ineqs">QPTEST</a></td>
 *   <td><span title="runtime in milliseconds">1.4</span> (<span title="iterations">48</span>)</td>
 *   <td><span title="runtime in milliseconds">1.7</span> (<span title="iterations">41</span>)</td>
 *   <td><span title="runtime in milliseconds">39.4</span> (<span title="iterations">372</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QRECIPE.SIF" title="180 vars, 67 eqs, 91 ineqs">QRECIPE</a></td>
 *   <td><span title="runtime in milliseconds">57.3</span> (<span title="iterations">474</span>)</td>
 *   <td><span title="runtime in milliseconds">74.6</span> (<span title="iterations">547</span>)</td>
 *   <td><span title="runtime in milliseconds">174.1</span> (<span title="iterations">979</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSC205.SIF" title="203 vars, 91 eqs, 205 ineqs">QSC205</a></td>
 *   <td><span title="runtime in milliseconds">12.6</span> (<span title="iterations">135</span>)</td>
 *   <td><span title="runtime in milliseconds">12.7</span> (<span title="iterations">93</span>)</td>
 *   <td><span title="runtime in milliseconds">12.1</span> (<span title="iterations">91</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR25.SIF" title="500 vars, 300 eqs, 471 ineqs">QSCAGR25</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">3</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCAGR7.SIF" title="140 vars, 84 eqs, 129 ineqs">QSCAGR7</a></td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM1.SIF" title="457 vars, 187 eqs, 330 ineqs">QSCFXM1</a></td>
 *   <td><span title="runtime in milliseconds">14.9</span> (<span title="iterations">58</span>)</td>
 *   <td><span title="runtime in milliseconds">16.0</span> (<span title="iterations">53</span>)</td>
 *   <td><span title="runtime in milliseconds">19.0</span> (<span title="iterations">55</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM2.SIF" title="914 vars, 374 eqs, 660 ineqs">QSCFXM2</a></td>
 *   <td><span title="runtime in milliseconds">31.4</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">33.0</span> (<span title="iterations">47</span>)</td>
 *   <td><span title="runtime in milliseconds">36.6</span> (<span title="iterations">45</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCFXM3.SIF" title="1371 vars, 561 eqs, 990 ineqs">QSCFXM3</a></td>
 *   <td><span title="runtime in milliseconds">34.8</span> (<span title="iterations">45</span>)</td>
 *   <td><span title="runtime in milliseconds">66.9</span> (<span title="iterations">59</span>)</td>
 *   <td><span title="runtime in milliseconds">77.4</span> (<span title="iterations">63</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCORPIO.SIF" title="358 vars, 280 eqs, 388 ineqs">QSCORPIO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">964.3</span> (<span title="iterations">3702</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCRS8.SIF" title="1169 vars, 384 eqs, 490 ineqs">QSCRS8</a></td>
 *   <td><span title="runtime in milliseconds">2.6</span> (<span title="iterations">22</span>)</td>
 *   <td><span title="runtime in milliseconds">10.5</span> (<span title="iterations">52</span>)</td>
 *   <td><span title="runtime in milliseconds">4.5</span> (<span title="iterations">25</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD1.SIF" title="760 vars, 77 eqs, 77 ineqs">QSCSD1</a></td>
 *   <td><span title="runtime in milliseconds">0.7</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">0.9</span> (<span title="iterations">5</span>)</td>
 *   <td><span title="runtime in milliseconds">2.4</span> (<span title="iterations">5</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD6.SIF" title="1350 vars, 147 eqs, 147 ineqs">QSCSD6</a></td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">1.6</span> (<span title="iterations">7</span>)</td>
 *   <td><span title="runtime in milliseconds">1.9</span> (<span title="iterations">7</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCSD8.SIF" title="2750 vars, 397 eqs, 397 ineqs">QSCSD8</a></td>
 *   <td><span title="runtime in milliseconds">3.6</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">4.1</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">3.0</span> (<span title="iterations">6</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP1.SIF" title="480 vars, 120 eqs, 300 ineqs">QSCTAP1</a></td>
 *   <td><span title="runtime in milliseconds">4.3</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">6.1</span> (<span title="iterations">25</span>)</td>
 *   <td><span title="runtime in milliseconds">7.7</span> (<span title="iterations">33</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP2.SIF" title="1880 vars, 470 eqs, 1090 ineqs">QSCTAP2</a></td>
 *   <td><span title="runtime in milliseconds">15.8</span> (<span title="iterations">26</span>)</td>
 *   <td><span title="runtime in milliseconds">17.5</span> (<span title="iterations">21</span>)</td>
 *   <td><span title="runtime in milliseconds">21.9</span> (<span title="iterations">21</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSCTAP3.SIF" title="2480 vars, 620 eqs, 1480 ineqs">QSCTAP3</a></td>
 *   <td><span title="runtime in milliseconds">34.6</span> (<span title="iterations">35</span>)</td>
 *   <td><span title="runtime in milliseconds">31.0</span> (<span title="iterations">28</span>)</td>
 *   <td><span title="runtime in milliseconds">36.4</span> (<span title="iterations">27</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSEBA.SIF" title="1028 vars, 507 eqs, 515 ineqs">QSEBA</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHARE1B.SIF" title="225 vars, 89 eqs, 117 ineqs">QSHARE1B</a></td>
 *   <td><span title="runtime in milliseconds">81.6</span> (<span title="iterations">512</span>)</td>
 *   <td><span title="runtime in milliseconds">82.2</span> (<span title="iterations">501</span>)</td>
 *   <td><span title="runtime in milliseconds">75.9</span> (<span title="iterations">420</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHELL.SIF" title="1775 vars, 534 eqs, 536 ineqs">QSHELL</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="runtime in milliseconds">74800.7</span> (<span title="iterations">4628</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04L.SIF" title="2118 vars, 354 eqs, 402 ineqs">QSHIP04L</a></td>
 *   <td><span title="runtime in milliseconds">2.8</span> (<span title="iterations">13</span>)</td>
 *   <td><span title="runtime in milliseconds">4.0</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">4.2</span> (<span title="iterations">12</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP04S.SIF" title="1458 vars, 354 eqs, 402 ineqs">QSHIP04S</a></td>
 *   <td><span title="runtime in milliseconds">2.3</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">2.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">3.4</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08L.SIF" title="4283 vars, 698 eqs, 778 ineqs">QSHIP08L</a></td>
 *   <td><span title="runtime in milliseconds">33.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">37.7</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">36.4</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP08S.SIF" title="2387 vars, 698 eqs, 778 ineqs">QSHIP08S</a></td>
 *   <td><span title="runtime in milliseconds">12.0</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">13.8</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">13.8</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12L.SIF" title="5427 vars, 1045 eqs, 1151 ineqs">QSHIP12L</a></td>
 *   <td><span title="runtime in milliseconds">130.4</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">132.6</span> (<span title="iterations">10</span>)</td>
 *   <td><span title="runtime in milliseconds">137.4</span> (<span title="iterations">10</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSHIP12S.SIF" title="2763 vars, 1045 eqs, 1151 ineqs">QSHIP12S</a></td>
 *   <td><span title="runtime in milliseconds">36.0</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">32.9</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">33.3</span> (<span title="iterations">11</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSIERRA.SIF" title="2036 vars, 528 eqs, 1227 ineqs">QSIERRA</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTAIR.SIF" title="467 vars, 209 eqs, 356 ineqs">QSTAIR</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/QSTANDAT.SIF" title="1075 vars, 160 eqs, 359 ineqs">QSTANDAT</a></td>
 *   <td><span title="runtime in milliseconds">5804.9</span> (<span title="iterations">4873</span>)</td>
 *   <td><span title="runtime in milliseconds">6072.4</span> (<span title="iterations">4841</span>)</td>
 *   <td><span title="runtime in milliseconds">6730.9</span> (<span title="iterations">4846</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/S268.SIF" title="5 vars, 5 ineqs">S268</a></td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">11</span>)</td>
 *   <td><span title="runtime in milliseconds">0.5</span> (<span title="iterations">12</span>)</td>
 *   <td><span title="runtime in milliseconds">0.6</span> (<span title="iterations">15</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP1.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP1</a></td>
 *   <td><span title="runtime in milliseconds">8371.7</span> (<span title="iterations">2833</span>)</td>
 *   <td><span title="runtime in milliseconds">13610.1</span> (<span title="iterations">3963</span>)</td>
 *   <td><span title="runtime in milliseconds">14707.5</span> (<span title="iterations">3172</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/STCQP2.SIF" title="4097 vars, 2052 eqs, 2052 ineqs">STCQP2</a></td>
 *   <td><span title="runtime in milliseconds">6753.4</span> (<span title="iterations">1441</span>)</td>
 *   <td><span title="runtime in milliseconds">5531.3</span> (<span title="iterations">1114</span>)</td>
 *   <td><span title="runtime in milliseconds">7308.1</span> (<span title="iterations">1266</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/TAME.SIF" title="2 vars, 1 eqs, 1 ineqs">TAME</a></td>
 *   <td><span title="runtime in milliseconds">0.2</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.3</span> (<span title="iterations">6</span>)</td>
 *   <td><span title="runtime in milliseconds">0.4</span> (<span title="iterations">6</span>)</td>
 *  </tr>
 *  <tr>
 *   <td><a href="ftp://ftp.numerical.rl.ac.uk/pub/cuter/marosmeszaros/YAO.SIF" title="2002 vars, 2000 ineqs">YAO</a></td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *   <td><span title="failed" style="color:red;">FAIL</span> (<span title="iterations">5000</span>)</td>
 *  </tr>
 *  </table>
 * </div>
 */