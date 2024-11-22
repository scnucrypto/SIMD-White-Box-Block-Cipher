#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 128
#define WORD_SIZE 64
#define WORD_TYPE uint64_t
#define WORD_IN_TYPE SCNx64
#define WORD_OUT_TYPE PRIx64
#define WORD_CONSTANT_TYPE UINT64_C
#define WORD_PARITY_FUNCTION __builtin_parityll
#define WORD_MASK 0xffffffffffffffff
#define ROUNDS 2

WORD_TYPE MATRICES[ROUNDS + 1][BLOCK_SIZE][2] = {
    {{WORD_CONSTANT_TYPE(256), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(512), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1024), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2048), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4096), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8192), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16384), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32768), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(65536), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(131072), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(262144), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(524288), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1048576), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2097152), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4194304), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8388608), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16777216), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(33554432), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(67108864), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(134217728), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(268435456), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(536870912), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1073741824), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2147483648), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4294967296), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8589934592), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(17179869184), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(34359738368), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(68719476736), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(137438953472), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(274877906944), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(549755813888), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1099511627776), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2199023255552), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4398046511104), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8796093022208), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(17592186044416), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(35184372088832), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(70368744177664), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(140737488355328), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(281474976710656), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(562949953421312), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1125899906842624), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2251799813685248), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4503599627370496), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(9007199254740992), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(18014398509481984), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(36028797018963968), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(72057594037927936), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(144115188075855872), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(288230376151711744), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(576460752303423488), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1152921504606846976), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2305843009213693952), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4611686018427387904), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(9223372036854775808), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(64), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(128), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(64)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(128)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(256)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(512)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1024)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2048)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4096)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8192)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16384)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32768)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(65536)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(131072)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(262144)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(524288)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1048576)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2097152)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4194304)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8388608)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16777216)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(33554432)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(67108864)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(134217728)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(268435456)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(536870912)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1073741824)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2147483648)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4294967296)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8589934592)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(17179869184)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(34359738368)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(68719476736)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(137438953472)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(274877906944)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(549755813888)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1099511627776)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2199023255552)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4398046511104)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8796093022208)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(17592186044416)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(35184372088832)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(70368744177664)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(140737488355328)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(281474976710656)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(562949953421312)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1125899906842624)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2251799813685248)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4503599627370496)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(9007199254740992)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(18014398509481984)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(36028797018963968)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(72057594037927936)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(144115188075855872)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(288230376151711744)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(576460752303423488)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1152921504606846976)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2305843009213693952)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4611686018427387904)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(9223372036854775808)}},
    {{WORD_CONSTANT_TYPE(11692492006296433913), WORD_CONSTANT_TYPE(13694858061146524295)}, {WORD_CONSTANT_TYPE(17799795235883262810), WORD_CONSTANT_TYPE(1326936886382609593)}, {WORD_CONSTANT_TYPE(4266487258131324240), WORD_CONSTANT_TYPE(9199769370056057488)}, {WORD_CONSTANT_TYPE(5124672878444831120), WORD_CONSTANT_TYPE(8663162151242056195)}, {WORD_CONSTANT_TYPE(6746177565446244814), WORD_CONSTANT_TYPE(8344548298821156320)}, {WORD_CONSTANT_TYPE(5140711247826111856), WORD_CONSTANT_TYPE(11393260616811727738)}, {WORD_CONSTANT_TYPE(14073316734741341181), WORD_CONSTANT_TYPE(750881327847697251)}, {WORD_CONSTANT_TYPE(1773898965728772814), WORD_CONSTANT_TYPE(15639654999608293581)}, {WORD_CONSTANT_TYPE(7985864657912257267), WORD_CONSTANT_TYPE(5918751973988917511)}, {WORD_CONSTANT_TYPE(18134516014568504303), WORD_CONSTANT_TYPE(5708305964481987447)}, {WORD_CONSTANT_TYPE(10628312617882275901), WORD_CONSTANT_TYPE(8763948994982661189)}, {WORD_CONSTANT_TYPE(3019963577686637202), WORD_CONSTANT_TYPE(7859072594541792924)}, {WORD_CONSTANT_TYPE(5051138265959342529), WORD_CONSTANT_TYPE(6420466295277956396)}, {WORD_CONSTANT_TYPE(2407188469696568403), WORD_CONSTANT_TYPE(8720678210518246957)}, {WORD_CONSTANT_TYPE(5737738838037876875), WORD_CONSTANT_TYPE(18163153184634048749)}, {WORD_CONSTANT_TYPE(14021380204112068698), WORD_CONSTANT_TYPE(14717476563172580171)}, {WORD_CONSTANT_TYPE(2700631314084164966), WORD_CONSTANT_TYPE(10132451430682762311)}, {WORD_CONSTANT_TYPE(17813737215381454476), WORD_CONSTANT_TYPE(15276486836838355146)}, {WORD_CONSTANT_TYPE(10402605818889779152), WORD_CONSTANT_TYPE(7720144995185973364)}, {WORD_CONSTANT_TYPE(15060447760351526440), WORD_CONSTANT_TYPE(16763334621430434230)}, {WORD_CONSTANT_TYPE(2664808327917583336), WORD_CONSTANT_TYPE(5429635792744570276)}, {WORD_CONSTANT_TYPE(4594602024413417575), WORD_CONSTANT_TYPE(10971563379203420252)}, {WORD_CONSTANT_TYPE(3215463692290552715), WORD_CONSTANT_TYPE(2983042445776113869)}, {WORD_CONSTANT_TYPE(2038303518340870001), WORD_CONSTANT_TYPE(4129917476668599839)}, {WORD_CONSTANT_TYPE(3723612030171880220), WORD_CONSTANT_TYPE(8846873587162192175)}, {WORD_CONSTANT_TYPE(4028645949281579636), WORD_CONSTANT_TYPE(13611546548022459120)}, {WORD_CONSTANT_TYPE(15309234971735228490), WORD_CONSTANT_TYPE(14218934903037720581)}, {WORD_CONSTANT_TYPE(2968097359406587010), WORD_CONSTANT_TYPE(804436509468450578)}, {WORD_CONSTANT_TYPE(15998526155222662850), WORD_CONSTANT_TYPE(4365268346453960182)}, {WORD_CONSTANT_TYPE(7230246675077173809), WORD_CONSTANT_TYPE(8785156625347160729)}, {WORD_CONSTANT_TYPE(2843539265038792735), WORD_CONSTANT_TYPE(6769278015081733834)}, {WORD_CONSTANT_TYPE(11774706014856023933), WORD_CONSTANT_TYPE(17784331411107376977)}, {WORD_CONSTANT_TYPE(17312142439640627728), WORD_CONSTANT_TYPE(15860059350954167381)}, {WORD_CONSTANT_TYPE(15962296285620187602), WORD_CONSTANT_TYPE(1659179189711397281)}, {WORD_CONSTANT_TYPE(5808249918212896841), WORD_CONSTANT_TYPE(16011359489187493231)}, {WORD_CONSTANT_TYPE(16033128560530125824), WORD_CONSTANT_TYPE(17988623682515375482)}, {WORD_CONSTANT_TYPE(3770825307192412239), WORD_CONSTANT_TYPE(17294437723268040131)}, {WORD_CONSTANT_TYPE(6124943211146774573), WORD_CONSTANT_TYPE(13204229396628210855)}, {WORD_CONSTANT_TYPE(13883963264052954480), WORD_CONSTANT_TYPE(10149228527485995541)}, {WORD_CONSTANT_TYPE(8823593332829015124), WORD_CONSTANT_TYPE(6365217699829084270)}, {WORD_CONSTANT_TYPE(14627238310116379968), WORD_CONSTANT_TYPE(11938124569053922380)}, {WORD_CONSTANT_TYPE(15851381439188300827), WORD_CONSTANT_TYPE(7977576863632635288)}, {WORD_CONSTANT_TYPE(9443211718667049536), WORD_CONSTANT_TYPE(12010260564036788080)}, {WORD_CONSTANT_TYPE(2354163265063284530), WORD_CONSTANT_TYPE(12512900524683203315)}, {WORD_CONSTANT_TYPE(10266291536509201023), WORD_CONSTANT_TYPE(5410688134939180204)}, {WORD_CONSTANT_TYPE(15774167678246645147), WORD_CONSTANT_TYPE(13703497292336554136)}, {WORD_CONSTANT_TYPE(17356128372701781506), WORD_CONSTANT_TYPE(6857800499587379331)}, {WORD_CONSTANT_TYPE(4529167887605862159), WORD_CONSTANT_TYPE(2672856619984845320)}, {WORD_CONSTANT_TYPE(1384638833493351365), WORD_CONSTANT_TYPE(14293267461807117012)}, {WORD_CONSTANT_TYPE(13333236133926707123), WORD_CONSTANT_TYPE(15837643232733052632)}, {WORD_CONSTANT_TYPE(14004994924785888562), WORD_CONSTANT_TYPE(8592261695932027822)}, {WORD_CONSTANT_TYPE(10875614163008234007), WORD_CONSTANT_TYPE(13985590621208527865)}, {WORD_CONSTANT_TYPE(3718849715621704498), WORD_CONSTANT_TYPE(9382727186025781541)}, {WORD_CONSTANT_TYPE(13147586135856087219), WORD_CONSTANT_TYPE(4754230719813386075)}, {WORD_CONSTANT_TYPE(15647413202714759562), WORD_CONSTANT_TYPE(13331088051711162621)}, {WORD_CONSTANT_TYPE(3323364452351539891), WORD_CONSTANT_TYPE(13564417210129131036)}, {WORD_CONSTANT_TYPE(2161257978482305027), WORD_CONSTANT_TYPE(17083104566167594334)}, {WORD_CONSTANT_TYPE(14139491399182128575), WORD_CONSTANT_TYPE(14321304812344933873)}, {WORD_CONSTANT_TYPE(11595798923178935648), WORD_CONSTANT_TYPE(1151188729994523067)}, {WORD_CONSTANT_TYPE(16122560943358802719), WORD_CONSTANT_TYPE(48149111613450687)}, {WORD_CONSTANT_TYPE(3209074931053680875), WORD_CONSTANT_TYPE(514827419883520131)}, {WORD_CONSTANT_TYPE(5016221054703257175), WORD_CONSTANT_TYPE(10398972981845567655)}, {WORD_CONSTANT_TYPE(2153496238191869935), WORD_CONSTANT_TYPE(653399482399071841)}, {WORD_CONSTANT_TYPE(7630629621669538575), WORD_CONSTANT_TYPE(17117160972852803885)}, {WORD_CONSTANT_TYPE(12166838950683241006), WORD_CONSTANT_TYPE(3969258248203309284)}, {WORD_CONSTANT_TYPE(12182360905061020709), WORD_CONSTANT_TYPE(16218669862622936050)}, {WORD_CONSTANT_TYPE(9166815509878103112), WORD_CONSTANT_TYPE(14072115433595047011)}, {WORD_CONSTANT_TYPE(4226245472113245318), WORD_CONSTANT_TYPE(777187249606986641)}, {WORD_CONSTANT_TYPE(3215954928745811025), WORD_CONSTANT_TYPE(4036633725234388348)}, {WORD_CONSTANT_TYPE(15758598584893712530), WORD_CONSTANT_TYPE(10017682528107253003)}, {WORD_CONSTANT_TYPE(14119473607582183776), WORD_CONSTANT_TYPE(14869541464570062721)}, {WORD_CONSTANT_TYPE(1925072830162587944), WORD_CONSTANT_TYPE(3316406561569055764)}, {WORD_CONSTANT_TYPE(15812485621353631133), WORD_CONSTANT_TYPE(6467121290511028958)}, {WORD_CONSTANT_TYPE(2234701299354026226), WORD_CONSTANT_TYPE(1555067927470516903)}, {WORD_CONSTANT_TYPE(3907951149868517331), WORD_CONSTANT_TYPE(16776924358305130952)}, {WORD_CONSTANT_TYPE(4372016825453903742), WORD_CONSTANT_TYPE(2013051462304917319)}, {WORD_CONSTANT_TYPE(16521431853395030511), WORD_CONSTANT_TYPE(3837092218396396386)}, {WORD_CONSTANT_TYPE(6890778007472848046), WORD_CONSTANT_TYPE(4582253894853617003)}, {WORD_CONSTANT_TYPE(6686493602056259959), WORD_CONSTANT_TYPE(7442063833003763895)}, {WORD_CONSTANT_TYPE(629114782023077526), WORD_CONSTANT_TYPE(1659752028845591897)}, {WORD_CONSTANT_TYPE(16982433325385489243), WORD_CONSTANT_TYPE(18225656593865828543)}, {WORD_CONSTANT_TYPE(3793995466830315495), WORD_CONSTANT_TYPE(13537523110099371698)}, {WORD_CONSTANT_TYPE(14484085289448581877), WORD_CONSTANT_TYPE(14712414332191688371)}, {WORD_CONSTANT_TYPE(5553468133748082389), WORD_CONSTANT_TYPE(12791090740609947305)}, {WORD_CONSTANT_TYPE(15921966818357708017), WORD_CONSTANT_TYPE(6012049830669548108)}, {WORD_CONSTANT_TYPE(1197843645791702606), WORD_CONSTANT_TYPE(16459471059459044271)}, {WORD_CONSTANT_TYPE(10322904327867339638), WORD_CONSTANT_TYPE(10446145651311458201)}, {WORD_CONSTANT_TYPE(12571846241617026909), WORD_CONSTANT_TYPE(16214702041649059101)}, {WORD_CONSTANT_TYPE(5160006762842802901), WORD_CONSTANT_TYPE(11471040197545169276)}, {WORD_CONSTANT_TYPE(5958438699059604298), WORD_CONSTANT_TYPE(15566357757169403108)}, {WORD_CONSTANT_TYPE(3679257443141601514), WORD_CONSTANT_TYPE(5358699298500052917)}, {WORD_CONSTANT_TYPE(14164901097313878434), WORD_CONSTANT_TYPE(6211705685346816280)}, {WORD_CONSTANT_TYPE(9140735754368254665), WORD_CONSTANT_TYPE(8480625449503653307)}, {WORD_CONSTANT_TYPE(11702014602448262555), WORD_CONSTANT_TYPE(2903060521568615273)}, {WORD_CONSTANT_TYPE(7156498917354457670), WORD_CONSTANT_TYPE(7475404266832072796)}, {WORD_CONSTANT_TYPE(9246390055553982599), WORD_CONSTANT_TYPE(1444009969345766339)}, {WORD_CONSTANT_TYPE(9716947318737140462), WORD_CONSTANT_TYPE(1335845546174238699)}, {WORD_CONSTANT_TYPE(14603409409907672223), WORD_CONSTANT_TYPE(14806921850685205766)}, {WORD_CONSTANT_TYPE(18117821112217165734), WORD_CONSTANT_TYPE(2415827822316862504)}, {WORD_CONSTANT_TYPE(3709831207267053321), WORD_CONSTANT_TYPE(17297608875744408410)}, {WORD_CONSTANT_TYPE(6462292270528200913), WORD_CONSTANT_TYPE(14415952614606939943)}, {WORD_CONSTANT_TYPE(5140330091246898613), WORD_CONSTANT_TYPE(17197140496252357630)}, {WORD_CONSTANT_TYPE(1545093089456776453), WORD_CONSTANT_TYPE(7760270093485842673)}, {WORD_CONSTANT_TYPE(5056487098993812097), WORD_CONSTANT_TYPE(7575733394181638846)}, {WORD_CONSTANT_TYPE(12972511379339469932), WORD_CONSTANT_TYPE(5136993398598353356)}, {WORD_CONSTANT_TYPE(3252148080853457607), WORD_CONSTANT_TYPE(15756523867040499707)}, {WORD_CONSTANT_TYPE(2060622298245713026), WORD_CONSTANT_TYPE(15402512620980211117)}, {WORD_CONSTANT_TYPE(7206280822219643189), WORD_CONSTANT_TYPE(5141348378526280104)}, {WORD_CONSTANT_TYPE(14475882320609142692), WORD_CONSTANT_TYPE(13966298146203029074)}, {WORD_CONSTANT_TYPE(11462632618168703282), WORD_CONSTANT_TYPE(17821869120876370364)}, {WORD_CONSTANT_TYPE(11037667605545543000), WORD_CONSTANT_TYPE(4525029275906155791)}, {WORD_CONSTANT_TYPE(13377403998526642378), WORD_CONSTANT_TYPE(17046468933398892622)}, {WORD_CONSTANT_TYPE(17055976986137774720), WORD_CONSTANT_TYPE(16422797038557112440)}, {WORD_CONSTANT_TYPE(6157639802101185896), WORD_CONSTANT_TYPE(15746553031776689490)}, {WORD_CONSTANT_TYPE(17222169758664308772), WORD_CONSTANT_TYPE(6768316704483034150)}, {WORD_CONSTANT_TYPE(12262540082055874598), WORD_CONSTANT_TYPE(12618318937087982082)}, {WORD_CONSTANT_TYPE(13334504740980095351), WORD_CONSTANT_TYPE(14077036770880355589)}, {WORD_CONSTANT_TYPE(2590986675512695440), WORD_CONSTANT_TYPE(16717590522373508332)}, {WORD_CONSTANT_TYPE(5371228034283056894), WORD_CONSTANT_TYPE(15804057073650631339)}, {WORD_CONSTANT_TYPE(5077397222240421627), WORD_CONSTANT_TYPE(13463437193226819143)}, {WORD_CONSTANT_TYPE(11021466722703025770), WORD_CONSTANT_TYPE(17358089113698940253)}, {WORD_CONSTANT_TYPE(985429084834787477), WORD_CONSTANT_TYPE(97500934391992708)}, {WORD_CONSTANT_TYPE(12574043692225042517), WORD_CONSTANT_TYPE(2322064903190070507)}, {WORD_CONSTANT_TYPE(16068403901387774219), WORD_CONSTANT_TYPE(16316697212416285136)}, {WORD_CONSTANT_TYPE(17312981753730493128), WORD_CONSTANT_TYPE(3062393129504857290)}, {WORD_CONSTANT_TYPE(7920409835093406735), WORD_CONSTANT_TYPE(3939805193209362867)}, {WORD_CONSTANT_TYPE(15640302128640377727), WORD_CONSTANT_TYPE(12120736666777704438)}, {WORD_CONSTANT_TYPE(13712912391480740920), WORD_CONSTANT_TYPE(940978724708468276)}},
    {{WORD_CONSTANT_TYPE(72057594037927936), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(144115188075855872), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(288230376151711744), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(576460752303423488), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1152921504606846976), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2305843009213693952), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4611686018427387904), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(9223372036854775808), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(64), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(128), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(256), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(512), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1024), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2048), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4096), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8192), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16384), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(32768), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(65536), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(131072), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(262144), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(524288), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1048576), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2097152), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4194304), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8388608), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(16777216), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(33554432), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(67108864), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(134217728), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(268435456), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(536870912), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1073741824), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2147483648), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4294967296), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8589934592), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(17179869184), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(34359738368), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(68719476736), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(137438953472), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(274877906944), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(549755813888), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1099511627776), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2199023255552), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4398046511104), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(8796093022208), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(17592186044416), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(35184372088832), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(70368744177664), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(140737488355328), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(281474976710656), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(562949953421312), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(1125899906842624), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(2251799813685248), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(4503599627370496), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(9007199254740992), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(18014398509481984), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(36028797018963968), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(64)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(128)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(256)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(512)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1024)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2048)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4096)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8192)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16384)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(32768)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(65536)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(131072)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(262144)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(524288)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1048576)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2097152)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4194304)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8388608)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(16777216)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(33554432)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(67108864)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(134217728)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(268435456)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(536870912)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1073741824)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2147483648)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4294967296)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8589934592)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(17179869184)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(34359738368)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(68719476736)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(137438953472)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(274877906944)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(549755813888)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1099511627776)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2199023255552)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4398046511104)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(8796093022208)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(17592186044416)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(35184372088832)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(70368744177664)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(140737488355328)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(281474976710656)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(562949953421312)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1125899906842624)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2251799813685248)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4503599627370496)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(9007199254740992)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(18014398509481984)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(36028797018963968)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(72057594037927936)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(144115188075855872)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(288230376151711744)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(576460752303423488)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(1152921504606846976)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(2305843009213693952)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(4611686018427387904)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(9223372036854775808)}}
};

WORD_TYPE VECTORS[ROUNDS + 1][2] = {{WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(0)}, {WORD_CONSTANT_TYPE(15193607361146245805), WORD_CONSTANT_TYPE(8980204467765845526)}, {WORD_CONSTANT_TYPE(0), WORD_CONSTANT_TYPE(0)}};

void matrix_vector_product(WORD_TYPE matrix[BLOCK_SIZE][2], WORD_TYPE xy[2], WORD_TYPE res[2]) {
    for (size_t i = WORD_SIZE; i-- > 0;) {
        res[0] = (res[0] << 1) | ((WORD_TYPE) WORD_PARITY_FUNCTION((matrix[i][0] & xy[0]) ^ (matrix[i][1] & xy[1])));
        res[1] = (res[1] << 1) | ((WORD_TYPE) WORD_PARITY_FUNCTION((matrix[WORD_SIZE + i][0] & xy[0]) ^ (matrix[WORD_SIZE + i][1] & xy[1])));
    }
}

void vector_addition(WORD_TYPE vector[2], WORD_TYPE xy[2]) {
    xy[0] ^= vector[0];
    xy[1] ^= vector[1];
}

void modular_addition(WORD_TYPE xy[2]) {
    xy[0] = (xy[0] + xy[1]) & WORD_MASK;
}

void modular_subtraction(WORD_TYPE xy[2]) {
    xy[0] -= xy[1];
}

int main(int argc, char *argv[]) {
    WORD_TYPE xy[2];
    WORD_TYPE res[2];
    if (argc < 3) {
        return -1;
    } else {
        sscanf(argv[1], "%" WORD_IN_TYPE, &xy[0]);
        sscanf(argv[2], "%" WORD_IN_TYPE, &xy[1]);
        res[0] = 0;
        res[1] = 0;
        matrix_vector_product(MATRICES[0], xy, res);
        vector_addition(VECTORS[0], res);
        modular_addition(res);
        vector_addition(VECTORS[1], res);
        xy[0] = 0;
        xy[1] = 0;
        matrix_vector_product(MATRICES[1], res, xy);
        modular_subtraction(xy);
        vector_addition(VECTORS[2], xy);
        res[0] = 0;
        res[1] = 0;
        matrix_vector_product(MATRICES[2], xy, res);
        printf("%" WORD_OUT_TYPE " %" WORD_OUT_TYPE "\n", res[0], res[1]);
    }
}