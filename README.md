# SW Professional Level

## How to build

### Using make

```ps1
mkdir build
cd build
cmake .. -G "MinGW Makefiles"
make # build all target
make -j8 # like above but faster
make Survival_Train # build single target
```

### Using Visual Studio (msbuild)

```ps1
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017"
cmake --build .
```

## Run

```ps1
cd build/Bacteria
./Bacteria
(Measure-Command {./Bacteria | Out-Default }).ToString() # To measure run time
```

## Advance Problems:

- [x] [8_Queen](Advance/8_Queen/README.md)
- [x] [Airplane_Game](Advance/Airplane_Game/README.md)
- [x] [Array_Game](Advance/Array_Game/README.md)
- [x] [Assigning_a_Meeting_Room](Advance/Assigning_a_Meeting_Room/README.md)
- [x] [Attacking_the_Citadel](Advance/Attacking_the_Citadel/README.md)
- [x] [Balloons_Shooter](Advance/Balloons_Shooter/README.md)
- [x] [Battle_City](Advance/Battle_City/README.md)
- [x] [Bipartitioning_Cities](Advance/Bipartitioning_Cities/README.md)
- [x] [Bishop](Advance/Bishop/README.md)
- [x] [Blackpink_View](Advance/Blackpink_View/README.md)
- [x] [Block_Dropping](Advance/Block_Dropping/README.md)
- [x] [Bridge](Advance/Bridge/README.md)
- [x] [Calculator_1](Advance/Calculator_1/README.md)
- [x] [Calculator_2](Advance/Calculator_2/README.md)
- [x] [Calculator_3](Advance/Calculator_3/README.md)
- [x] [Capture_Knight](Advance/Capture_Knight/README.md)
- [x] [Checking_cube](Advance/Checking_cube/README.md)
- [x] [Chess_rook](Advance/Chess_rook/README.md)
- [x] [Cleaning_Robot](Advance/Cleaning_Robot/README.md)
- [x] [Cosmic_Energy](Advance/Cosmic_Energy/README.md)
- [x] [Crazy_King](Advance/Crazy_King/README.md)
- [x] [Cryptogram_1](Advance/Cryptogram_1/README.md)
- [x] [Cryptogram_2](Advance/Cryptogram_2/README.md)
- [x] [Cryptogram_3](Advance/Cryptogram_3/README.md)
- [x] [Cutting_Paper](Advance/Cutting_Paper/README.md)
- [x] [Dominos](Advance/Dominos/README.md)
- [x] [Earning_Money_2](Advance/Earning_Money_2/README.md)
- [x] [Electrical_System](Advance/Electrical_System/README.md)
- [x] [Farm_Protect](Advance/Farm_Protect/README.md)
- [x] [Fast_robot](Advance/Fast_robot/README.md)
- [x] [Find_Cycle](Advance/Find_Cycle/README.md)
- [x] [Finding_Mode](Advance/Finding_Mode/README.md)
- [x] [Flatten](Advance/Flatten/README.md)
- [x] [Game_with_numbers](Advance/Game_with_numbers/README.md)
- [x] [GNS](Advance/GNS/README.md)
- [x] [Grid_Acid](Advance/Grid_Acid/README.md)
- [ ] [Honeymoon](Advance/Honeymoon/README.md)
- [x] [Hugo](Advance/Hugo/README.md)
- [ ] [Hugo_Advertising](Advance/Hugo_Advertising/README.md)
- [ ] [Hugo_Gold_Miner](Advance/Hugo_Gold_Miner/README.md)
- [ ] [Hugo_Gold_Miner_2](Advance/Hugo_Gold_Miner_2/README.md)
- [x] [Hugo_Homecoming](Advance/Hugo_Homecoming/README.md)
- [ ] [Hugo_Marathon](Advance/Hugo_Marathon/README.md)
- [x] [Hugo_Oil_Quest](Advance/Hugo_Oil_Quest/README.md)
- [ ] [Hugo_Region_Counting](Advance/Hugo_Region_Counting/README.md)
- [x] [Hugo_Shipper](Advance/Hugo_Shipper/README.md)
- [ ] [Hugo_Steals_Honey](Advance/Hugo_Steals_Honey/README.md)
- [ ] [Hugo_Takes_the_Train](Advance/Hugo_Takes_the_Train/README.md)
- [x] [Ice_Cave](Advance/Ice_Cave/README.md)
- [x] [Interstellar](Advance/Interstellar/README.md)
- [x] [Involution](Advance/Involution/README.md)
- [x] [Knight](Advance/Knight/README.md)
- [x] [Ladder_1](Advance/Ladder_1/README.md)
- [x] [Ladder_2](Advance/Ladder_2/README.md)
- [x] [Lake](Advance/Lake/README.md)
- [x] [Laughing_Bomb](Advance/Laughing_Bomb/README.md)
- [x] [Magnetic](Advance/Magnetic/README.md)
- [x] [Map_Coloring](Advance/Map_Coloring/README.md)
- [x] [Mario_Climb](Advance/Mario_Climb/README.md)
- [x] [Matrix_Product](Advance/Matrix_Product/README.md)
- [x] [Matrix_Sum](Advance/Matrix_Sum/README.md)
- [x] [Maze_1](Advance/Maze_1/README.md)
- [x] [Maze_2](Advance/Maze_2/README.md)
- [x] [Mountain_Waling](Advance/Mountain_Walking/README.md)
- [x] [Move_Cow](Advance/Move_Cow/README.md)
- [x] [Painting](Advance/Painting/README.md)
- [x] [Painting_The_Wall](Advance/Painting_The_Wall/README.md)
- [x] [Palindrome_1](Advance/Palindrome_1/README.md)
- [x] [Palindrome_2](Advance/Palindrome_2/README.md)
- [x] [Paring_Parentheses](Advance/Paring_Parentheses/README.md)
- [x] [Partition_1](Advance/Partition_1/README.md)
- [x] [Password](Advance/Password/README.md)
- [x] [Password_Generator](Advance/Password_Generator/README.md)
- [x] [Path_Finding](Advance/Path_Finding/README.md)
- [x] [Picking_up_Jewels](Advance/Picking_up_Jewels/README.md)
- [x] [Pizza_Location](Advance/Pizza_Location/README.md)
- [x] [Point_of_Balance_2](Advance/Point_of_Balance_2/README.md)
- [x] [Princess](Advance/Princess/README.md)
- [x] [Rectangle](Advance/Rectangle/README.md)
- [x] [Reflecting_Mirrors](Advance/Reflecting_Mirrors/README.md)
- [x] [Robot](Advance/Robot/README.md)
- [x] [Route_Finding](Advance/Route_Finding/README.md)
- [ ] [Saving_Energy](Advance/Saving_Energy/README.md)
- [x] [Sea_Level](Advance/Sea_Level/README.md)
- [x] [Sky_Map](Advance/Sky_Map/README.md)
- [x] [Stock_Exchange](Advance/Stock_Exchange/README.md)
- [x] [String](Advance/String/README.md)
- [x] [Sudoku_1](Advance/Sudoku_1/README.md)
- [x] [The_Battle_of_Robots](Advance/The_Battle_of_Robots/README.md)
- [ ] [The_Frog](Advance/The_Frog/README.md)
- [ ] [The_Settlers_of_Catan](Advance/The_Settlers_of_Catan/README.md)
- [ ] [Tree_Set_2](Advance/Tree_Set_2/README.md)
- [x] [Turn_Over_Game](Advance/Turn_Over_Game/README.md)
- [x] [Uniform_Distribution](Advance/Uniform_Distribution/README.md)
- [ ] [Upgrade_Computer](Advance/Upgrade_Computer/README.md)
- [x] [Vandalize_Electrical_System](Advance/Vandalize_Electrical_System/README.md)
- [x] [View](Advance/View/README.md)
- [x] [Village](Advance/Village/README.md)
- [x] [Vinaphone_Mobiphone_Viettel](Advance/Vinaphone_Mobiphone_Viettel/README.md)
- [x] [Visit_Department](Advance/Visit_Department/README.md)
- [x] [Wedding_1](Advance/Wedding_1/README.md)
- [x] [Wedding_2](Advance/Wedding_2/README.)
- [x] [Well_Project](Advance/Well_Project/README.md)

## Professional Problems

- [x] Bacteria
- [x] Civilization
- [x] Constellation_Search
- [x] Dictionary
- [x] Dungeon_escape
- [x] Image_Searching
- [x] Memory_System
- [x] Microorganism
- [x] Morning_Commute_Radio
- [x] Notepad_Program
- [x] Online_Streamer
- [x] Push
- [x] Reserved_bus
- [x] Scattered_Constellation_Tiles
- [x] Secondhand_Market_App
- [x] Soldier_Management
- [x] Stock_Price
- [x] Survival_Train
- [x] Table_of_Ranking
- [x] Toll_Discount
- [x] Value_of_Restaurant
- [x] Vocab_Sheet
- [x] Water_Tank_Installing
- [x] Web_Service
- [x] Word_Search
